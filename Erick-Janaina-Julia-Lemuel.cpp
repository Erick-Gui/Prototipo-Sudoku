//Importando as bibliotecas necessarias
#include <iostream>

#include <time.h>

#include <stdlib.h>

#include <math.h>

using namespace std;

//Inicializando a fun��o principal (main)
int main ()

{setlocale(LC_ALL, "portuguese");

    srand(time(NULL));

    //Criando as matrizes necessarias e inicializando-as em suas respectivas variaveis
    int matriz_resposta[9][9];

    int f, i, j, tentativa=0, dif=2, num=0, l=8, c=8;

    int mat0[9][9]={{4,9,5,2,8,7,3,6,1},{7,2,8,6,1,3,4,9,5},{3,6,1,9,5,4,7,2,8},{6,5,3,8,4,9,2,1,7},{9,8,4,1,7,2,6,5,3},{2,1,7,5,3,6,9,8,4},{1,3,2,4,6,5,8,7,9},{5,4,6,7,9,8,1,3,2},{8,7,9,3,2,1,5,4,6}};

    //Apresentando o Menu e incluindo-o em um do-while para ele n�o ser fechado ao acabar o jogo
    do{
        cout<<endl<<"1 - Jogar"<<endl<<endl<<endl;
        cout<<"2 - Dificuldade"<<endl<<endl<<endl;
        cout<<"3 - Sobre"      <<endl<<endl<<endl;
        cout<<"4 - Fim "       <<endl<<endl<<endl;

        //Apresentando o menu das dificuldades. Dificuldade padr�o = M�dio
        if(dif==1){
           cout<<"Dificuldade est� no f�cil"<<endl<<endl;
        }

        if(dif==2){
           cout<<"Dificuldade est� no m�dio"<<endl<<endl;
        }

        if(dif==3){
           cout<<"Dificuldade est� no dif�cil"<<endl<<endl;
        }

        cout<<"selecione uma op��o:"<<endl;
        cin>> num;
        system("cls");

        //Op��o do Menu para escolher dificuldade
        if(num==2){
            cout<<"escolha uma dificuldade: (1 - Facil, 2 - Medio, 3 - Dificil)"<<endl;
            cin>>dif;
            system("cls");
        }
        //Inicializando o jogo
        if(num==1){
            //Fun��o responsavel por escolher a matriz usada no jogo (aleat�rio)
            f=rand()%4+1;

            if(f==1){//matriz original

               for(i=0;i<9;i++){
                   for(j=0;j<9;j++){
                      matriz_resposta[i][j]=mat0[i][j];
                   }
               }
            }

            if(f==2){//matriz transposta

               for(j=0;j<9;j++){
                   for(i=0;i<9;i++){
                      matriz_resposta[j][i]=mat0[i][j];
                   }
               }
            }

            if(f==3){//invertida por linha

               for(j=0;j<9;j++){
                   for(i=0;i<9;i++){
                   matriz_resposta[i][j]=mat0[l][j];
                   l--;
                   }
                   l=8;
               }
            }

            if(f==4){//invertida por coluna

               for(i=0;i<9;i++){
                   for(j=0;j<9;j++){
                   matriz_resposta[i][j]=mat0[i][c];
                   c--;
                   }
                   c=8;
               }
            }

            int mat_sorteio[9][9]={0},  cont=0, a=0;
            //Inicializando o jogo na dificuldade facil
            if(dif==1){

               while(cont<41){ //sorteando as posi��es dos n�meros que ser�o mostrados ao jogador

                    for(i=0;i<9;i++){
                        for(j=0;j<9;j++){
                            i=rand()%9;
                            j=rand()%9;
                            if(mat_sorteio[i][j]==0&&cont<41){
                               mat_sorteio[i][j] = matriz_resposta[i][j];
                               cont++;}
                        }
                    }
                }
                //Apresentando a "tabela" do jogo, mostrando colunas e linhas
                do{
                    cout<<"  ---------------sudoku---------------"<<endl;
                    cout<<"    0   1   2   3   4   5   6   7   8 "<<endl;
                    cout<<"  ------------------------------------"<<endl;
                    int l=0;

                    for(i=0;i<9;i++){
                        cout<<l<<" "<<"| ";
                        l++;
                        for(j=0;j<9;j++){

                            if(mat_sorteio[i][j]==0){
                               cout<< "_   ";
                            }else{
                               cout<< mat_sorteio[i][j]<< "   ";
                            }
                        }
                        cout<<endl;
                    }
                    //Coletando as respostas do usuario, filtrando por linha e coluna
                    cout<<endl;
                    cout<<"onde possui o '_' est� dispon�vel para preencher"<<endl;
                    cout<<"digite a linha de 0 a 8:";
                    cin>>i;
                    cout<<"digite a coluna de 0 a 8:";
                    cin>>j;

                    if(mat_sorteio[i][j]==0){
                       cout<<"digite o n�mero da posi��o escolhida:";
                       cin>>mat_sorteio[i][j];
                       tentativa++;
                    }else{
                       cout<<"posi��o j� preenchida"<<endl;
                    }
                    //Verifica��o se o numero esta correto ou n�o
                    if(matriz_resposta[i][j]==mat_sorteio[i][j]){
                       cout<<"n�mero certo!"<<endl;
                       mat_sorteio[i][j] = mat_sorteio[i][j];
                    }

                    if(mat_sorteio[i][j]!=matriz_resposta[i][j]){
                       cout<<"n�mero errado, tente novamente!"<<endl;
                       mat_sorteio[i][j]=0;
                    }

                    a=0;
                    //for() para ver se o jogador ganhou
                    for(i=0;i<9;i++){
                        for(j=0;j<9;j++){

                            if(mat_sorteio[i][j]!=0){
                               a++;
                            }
                        }
                    }
                    //Apresentando que o usuario ganhou e o numero de tentativas necessarias
                    if(a==81){
                       cout<<"parab�ns! voc� venceu!"<<endl<<"foram necess�rias "<<tentativa<<" tentativas."<<endl;
                    }
                    system("pause");
                    system("cls");
                }
                while(a!=81);
            }
            //Iniciando o jogo na dificuldade m�dia, s� muda o numero de numeros que s�o substituidos por zero
            if(dif==2){

                while(cont<29){ //sorteando as posi��es dos n�meros que ser�o mostrados ao jogador

                    for(i=0;i<9;i++){
                        for(j=0;j<9;j++){
                            i=rand()%9;
                            j=rand()%9;

                            if(mat_sorteio[i][j]==0&&cont<29){
                               mat_sorteio[i][j] = matriz_resposta[i][j];
                               cont++;}
                        }
                    }
                }
                //Apresentando a "tabela" do jogo, mostrando colunas e linhas
                do{
                    cout<<"  ---------------sudoku---------------"<<endl;
                    cout<<"    0   1   2   3   4   5   6   7   8 "<<endl;
                    cout<<"  ------------------------------------"<<endl;
                    int l=0;

                    for(i=0;i<9;i++){
                        cout<<l<<" "<<"| ";
                        l++;
                        for(j=0;j<9;j++){

                            if(mat_sorteio[i][j]==0){
                               cout<< "_   ";
                            }else{
                               cout<< mat_sorteio[i][j]<< "   ";}
                        }
                        cout<<endl;
                    }
                    //Coletando as respostas do usuario, filtrando por linha e coluna
                    cout<<endl;
                    cout<<"onde possui o '_' est� dispon�vel para preencher"<<endl;
                    cout<<"digite a linha de 0 a 8:";
                    cin>>i;
                    cout<<"digite a coluna de 0 a 8:";
                    cin>>j;

                    if(mat_sorteio[i][j]==0){
                       cout<<"digite o n�mero da posi��o escolhida:";
                       cin>>mat_sorteio[i][j];
                       tentativa++;
                    }else{
                       cout<<"posi��o j� preenchida"<<endl;
                    }
                    //Verifica��o se o numero esta correto ou n�o
                    if(matriz_resposta[i][j]==mat_sorteio[i][j]){
                       cout<<"n�mero certo!"<<endl;
                    }

                    if(mat_sorteio[i][j]!=matriz_resposta[i][j]){
                       cout<<"n�mero errado, tente novamente!"<<endl;
                       mat_sorteio[i][j]=0;
                    }

                    a=0;
                    //for() para ver se o jogador ganhou
                    for(i=0;i<9;i++){
                        for(j=0;j<9;j++){

                            if(mat_sorteio[i][j]!=0){
                               a++;
                            }
                        }
                    }
                    //Apresentando que o usuario ganhou e o numero de tentativas necessarias
                    if(a==81){
                       cout<<"parab�ns! voc� venceu!"<<endl<<"foram necess�rias "<<tentativa<<" tentativas."<<endl;
                    }
                       system("pause");
                       system("cls");
                }
                while(a!=81);
            }
            //Inicializando o jogo na dificuldade dificil
            if(dif==3){

                while(cont<13){

                     for(i=0;i<9;i++){ //sorteando as posi��es dos n�meros que ser�o mostrados ao jogador
                         for(j=0;j<9;j++){
                             i=rand()%9;
                             j=rand()%9;

                             if(mat_sorteio[i][j]==0&&cont<13){
                                mat_sorteio[i][j] = matriz_resposta[i][j];
                                cont++;
                             }
                         }
                     }
                 }
                //Apresentando a "tabela" do jogo, mostrando colunas e linhas
                do{
                   cout<<"  ---------------sudoku---------------"<<endl;
                   cout<<"    0   1   2   3   4   5   6   7   8 "<<endl;
                   cout<<"  ------------------------------------"<<endl;
                   int l=0;

                   for(i=0;i<9;i++){
                       cout<<l<<" "<<"| ";
                       l++;
                       for(j=0;j<9;j++){

                           if(mat_sorteio[i][j]==0){
                              cout<< "_   ";
                           }else{
                              cout<< mat_sorteio[i][j]<< "   ";}
                       }
                       cout<<endl;
                    }
                    //Coletando as respostas do usuario, filtrando por linha e coluna
                    cout<<endl;
                    cout<<"onde possui o '_' est� dispon�vel para preencher"<<endl;
                    cout<<"digite a linha de 0 a 8:";
                    cin>>i;
                    cout<<"digite a coluna de 0 a 8:";
                    cin>>j;

                    if(mat_sorteio[i][j]==0){
                       cout<<"digite o n�mero da posi��o escolhida:";
                       cin>>mat_sorteio[i][j];
                       tentativa++;
                    }else{
                       cout<<"posi��o j� preenchida"<<endl;
                    }
                    //Verifica��o se o numero esta correto ou n�o
                    if(matriz_resposta[i][j]==mat_sorteio[i][j]){
                       cout<<"n�mero certo!"<<endl;
                    }

                    if(mat_sorteio[i][j]!=matriz_resposta[i][j]){
                       cout<<"n�mero errado, tente novamente!"<<endl;
                       mat_sorteio[i][j]=0;
                    }

                    a=0;
                    //for() para ver se o jogador ganhou
                    for(i=0;i<9;i++){
                        for(j=0;j<9;j++){

                            if(mat_sorteio[i][j]!=0){
                               a++;
                            }
                        }
                    }
                    //Apresentando que o usuario ganhou e o numero de tentativas necessarias
                    if(a==81){
                       cout<<"Parab�ns! voc� venceu!"<<endl<<"foram necess�rias "<<tentativa<<" tentativas."<<endl;
                    }
                       system("pause");
                       system("cls");
                 }
                while(a!=81);
            }
        }
        //Apresentando a op��o "Sobre" do menu
        if (num==3){
            cout << "Desenvolvedores:" << "\nErick Wolf, "<< " \nJanaina Fischer," << "\nJ�lia Maria dos Santos Herrera" << "\ne Lemuel Andrey Lopes de Paulo" << "\nJunho/2023" << "\nProfessora: Cristina Ono Horita" << "\nDisciplina: Algoritmos e Programa��o I."<< endl;
            system("pause");
            system("cls");
        }
    }

    while(num!=4);
    //Finalizando o jogo com a op��o "Fim" do menu
    if(num==4){
       cout << "Obrigado por jogar nosso jogo, volte sempre!"<<endl;
    }
    return 0;
}
