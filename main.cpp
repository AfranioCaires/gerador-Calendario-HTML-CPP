#include <iostream>
#include <fstream>

using namespace std;

ofstream fout;

void diaSemana				(int dia, int mes, int ano, int &diaSemana);
bool ehBissexto				(int ano);
int diasNoMes				(int mes, int ano);
void mostraCalendario		(int mes, int ano);
void mostraCalendario_anual (int ano);
void menu 					();
void switchMeses			(int mes, int ano);
void gerarCalendario_ano	(int ano);
void gerarCalendario_mes	(int ano, int mes);
void headerHTML				();
void footerHTML				();
int main (){

	menu();
		
	return 0;
}


void diaSemana(int dia, int mes, int ano, int &diaSemana) {
    int calculo_dia;
    calculo_dia = ano + dia + 3 * (mes + 1);

    if (mes > 2)
        ano = ano - 1;

    if (mes >= 3)
        calculo_dia -= int(0.4 * mes + 2.3);

    calculo_dia += (ano / 4) - int((ano / 100 + 1) * 0.75);
    calculo_dia %= 7;

    diaSemana = calculo_dia;
}

bool ehBissexto(int ano) {
	if ((ano % 4 == 0 && ano % 100 != 0) || (ano % 400 == 0)) 
		return true; // O ano é bissexto
	 else {
		return false; // O ano não é bissexto
	}
}

int diasNoMes(int mes, int ano) {
	if (mes < 1 || mes > 12) {
		return -1; // Mês inválido
}
	switch (mes) {
		case 4: case 6: case 9: case 11:
			return 30; // Meses com 30 dias
		case 2:
			if (ehBissexto(ano)) {
				return 29; // Fevereiro em ano bissexto
			} else {
				return 28; // Fevereiro em ano não bissexto
			}
		default:
			return 31; // Meses com 31 dias (janeiro e os demais)
	}
}

void mostraCalendario (int mes, int ano){
	int calendario[6][7];
	
	for (int i = 0; i < 6; i++){
		for (int j = 0; j < 7; j++)
			calendario[i][j] = 0;
	}
	

	int diaSemanaHandler;
	diaSemana(1, mes, ano, diaSemanaHandler);
	
	int dias = diasNoMes (mes, ano);
	
	int diaHandler = 1; 
	
	for (int i = diaSemanaHandler; i < 7; i++){
		calendario[0][i] = diaHandler;
		diaHandler++;
	}
	
	for (int i = 1; i < 6; i++){
		for (int j = 0; j < 7; j++){
			if (diaHandler <= dias) {
				calendario[i][j] = diaHandler;
				diaHandler++;
			}
		}
	}
	
	switchMeses(mes, ano);
	
	fout << "<table> <tr>"
		 << "<th><span>D</span></th>"
		 << "<th>S</th>"
		 << "<th>T</th>"
		 << "<th>Q</th>"
		 << "<th>Q</th>"
		 << "<th>S</th>"
		 << "<th>S</th>"
		 << "</tr>";
	
	for (int i = 0; i < 6; i++){
		fout << "<tr>";
		for (int j = 0; j < 7; j++){
			if(calendario[i][j] != 0){
				fout << "<td>" << calendario[i][j] << "</td>";
			}
			else {
				fout << "<td></td>";
			}
		}
		fout << "</tr>";
	}
	
	
}

void menu() {
    cout << "--------- GERADOR DE CALENDARIO EM HTML ----------\n\n"
        << "Comandos: \n\n"
        << "\t1. Mensal\n"
        << "\t2. Anual\n"
        << "\t3. Sair\n"
        << "\n\n Digite um numero: ";

    int input;
    cin >> input;

    switch (input) {
    case 1:
        {
            system("cls");
            int ano, mes;
            cout << "Digite o mes e o ano para gerar o calendário.\n";

            do {
                cout << "\tMes (1 - 12): ";
                cin >> mes;
                if (mes < 1 || mes > 12) {
                    cout << "\aMes invalido. Por favor, digite um mes entre 1 e 12." << endl;
                }
            } while (mes < 1 || mes > 12);

            do {
                cout << "\tAno: ";
                cin >> ano;
                if (ano < 1) {
                    cout << "\aAno invalido. Por favor, digite um ano maior que zero." << endl;
                }
            } while (ano < 1);

            fout.open("index.html");
            gerarCalendario_mes(ano, mes);
            fout.close();
            break;
        }

    case 2:
        {
            system("cls");
            int ano_;
            cout << "Digite o ano para gerar o calendario: " << endl;
            do {
                cout << "\tAno: ";
                cin >> ano_;
                if (ano_ < 1) {
                    cout << "\aAno invalido. Por favor, digite um ano maior que zero." << endl;
                }
            } while (ano_ < 1);

            fout.open("index.html");
            gerarCalendario_ano(ano_);
            cout << "\nCalendario criado com sucesso!" << endl;
            fout.close();
            break;
        }

    case 3:
    	system("cls");
        cout << "Saindo do programa. Adeus!" << endl;
        break;
}

}


void mostraCalendario_anual (int ano){
	for (int mes = 1; mes <= 12; mes++){
		
		if (mes != 1)
			fout << "</table></section>";
	
		
		 mostraCalendario(mes, ano);
		if (mes == 12)
			fout  << "</table></section>";
	}
	
}

void gerarCalendario_ano(int ano) {
	
	headerHTML();
	
	mostraCalendario_anual(ano);

	footerHTML();

}

void gerarCalendario_mes(int ano, int mes) {
	headerHTML();
	
	mostraCalendario(mes,ano);

	footerHTML();

}

void switchMeses(int mes, int ano){
		switch (mes) {
            case 1:
                fout << "<section class=\"mes\"><h2>Jan" << "<span>" << ano << "</span></h2>" << endl;
                break;
            case 2:
                fout << "<section class=\"mes\"><h2>fev" << "<span>" << ano << "</span></h2>" << endl;
                break;
            case 3:
                fout << "<section class=\"mes\"><h2>mar" << "<span>" << ano << "</span></h2>" << endl;
                break;
            case 4:
                fout << "<section class=\"mes\"><h2>abr" << "<span>" << ano << "</span></h2>" << endl;
                break;
            case 5:
                fout << "<section class=\"mes\"><h2>mai" << "<span>" << ano << "</span></h2>" << endl;
                break;
            case 6:
                fout << "<section class=\"mes\"><h2>jun" << "<span>" << ano << "</span></h2>" << endl;
                break;
            case 7:
                fout << "<section class=\"mes\"><h2>jul" << "<span>" << ano << "</span></h2>" << endl;
                break;
            case 8:
                fout << "<section class=\"mes\"><h2>ago" << "<span>" << ano << "</span></h2>" << endl;
                break;
            case 9:
                fout << "<section class=\"mes\"><h2>set" << "<span>" << ano << "</span></h2>" << endl;
                break;
            case 10:
                fout << "<section class=\"mes\"><h2>out" << "<span>" << ano << "</span></h2>" << endl;
                break;
            case 11:
                fout << "<section class=\"mes\"><h2>nov" << "<span>" << ano << "</span></h2>" << endl;
                break;
            case 12:
                fout << "<section class=\"mes\"><h2>dez" << "<span>" << ano << "</span></h2>" << endl;
                break;
        }
}

void headerHTML() {
    fout << "<!DOCTYPE html> <html lang=\"pt-BR\">"
         << "<head> <meta charset=\"UTF-8\">"
         << "<meta name=\"viewport\" content=\"width=device-width, initial-scale=1.0\">"
         << "<title>Calend&aacute;rio</title>"
         << "<link href=\"https://fonts.googleapis.com/css?family=Open+Sans:300,400,600,700,800&display=swap\" rel=\"stylesheet\">"
         << "<style>"
         << "  body {"
         << "    padding: 40px 0;"
         << "    margin: 0;"
         << "    box-sizing: border-box;"
         << "    font-family: 'Open Sans', sans-serif;"
         << "    font-size: 14px;"
         << "    background-color: #ecf1f8;"
         << "    -webkit-font-smoothing: antialiased;"
         << "    display: grid;"
         << "    grid-template-columns: repeat(auto-fit, minmax(320px, max-content));"
         << "    justify-content: center;"
         << "    gap: 30px;"
         << "  }"
         << "  body h1 {"
         << "    grid-column: 1/-1;"
         << "    display: flex;"
         << "    justify-content: space-between;"
         << "    color: #262626;"
         << "  }"
         << "  .mes {"
         << "    border-radius: 18px;"
         << "    padding: 20px;"
         << "    background-color: #fff;"
         << "    color: #262626;"
         << "    box-shadow: 0 1px 3px 0 rgba(0, 0, 0, 0.1), 0 1px 2px -1px rgba(0, 0, 0, 0.1);"
         << "  }"
         << "  .mes h2 {"
         << "    padding: 0 14px;"
         << "    display: flex;"
         << "    text-transform: uppercase;"
         << "    justify-content: space-between;"
         << "  }"
         << "  .mes h2 span {"
         << "    color: #ccc;"
         << "  }"
         << "  .mes table {"
         << "    width: 100%;"
         << "    border-collapse: collapse;"
         << "  }"
         << "  .mes th {"
         << "    font-size: 1rem;"
         << "    color: gray;"
         << "    font-weight: 600;"
         << "    border-bottom: 1px solid #eee;"
         << "  }"
         << "  .mes th span {"
         << "    color: tomato;"
         << "  }"
         << "  .mes th, .mes td {"
         << "    text-align: center;"
         << "    padding: 10px;"
         << "  }"
         << "  .mes td:hover {"
         << "    font-weight: 600;"
         << "  }"
         << "</style>"
         << "</head>"
         << "<body>"
         << "<h1>Calend&aacute;rio<span>&#128197;</span></h1>";
}


void footerHTML (){
	fout << "</body></html>";
}
