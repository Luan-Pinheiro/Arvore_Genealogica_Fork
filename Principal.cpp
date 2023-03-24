/* ***************************************************************
* Autor............: Luan Pinheiro Azevedo
* Matricula........: 202110904
* Inicio...........: 18/03/2023
* Ultima alteracao.: 21/03/2023
* Nome.............: Arvore genealógica em C++
* Funcao...........: Simulação de uma arvore hereditaria utilizando divizao de processos com o fork na linguagem c++
*************************************************************** */

#include <iostream>
#include <unistd.h>
#include <sys/types.h>
#include <stdlib.h>
using namespace std;

int main(){
    cout << "\n***  INÍCIO DA ÁRVORE  ***"<<endl;;
    pid_t processIdentifier;//identificacao do processo a ser utilizado
    processIdentifier = fork(); // aqui ocorre a criacao do processo do primeiro filho
    if(processIdentifier < 0){// tratamento em caso de falha na criacao do processo (funcao fork() retornaria -1)
        cerr << "ERRO!"<<endl;
        exit(1);//encerrando 'processo' com falha
    }
    else if(processIdentifier == 0){//com o novo processo gerado através do comando fork() o identificador deste passa a ser 0
        sleep(22);/*estabelecendo temporizador em segundos (1 segundo correspondendo a 1 ano na simulacao) para 
        para dar sequencia no processo*/
        cout << "Nasceu o primeiro filho!" << endl;
        cout << "ID do filho: " << getpid()<< endl; // funcao getpid() retorna o identificador ID do processo
        cout << "ID do pai: " << getppid() << endl << endl;// funcao getppid() retorna o identificador ID do criador (pai) do processo
        processIdentifier = fork();// criacao do processo neto
        if(processIdentifier < 0){// tratamento em caso de falha na criacao do processo (funcao fork() retornaria -1)
                cout << "ERRO!"<<endl;
                exit(1);//encerrando 'processo' com falha
        }
        else if(processIdentifier == 0){//com o novo processo gerado através do comando fork() o identificador deste passa a ser 0
            sleep(16);/*estabelecendo temporizador em segundos (1 segundo correspondendo a 1 ano na simulacao) para 
            para dar sequencia no processo*/
            cout << "Nasceu o primeiro neto!" << endl;
            cout << "ID do filho: " << getpid()<< endl;// funcao getpid() retorna o identificador ID do processo
            cout << "ID do pai: " << getppid() << endl << endl;// funcao getppid() retorna o identificador ID do criador (pai) do processo
            processIdentifier = fork();//criacao do processo do bisneto
            if(processIdentifier < 0){// tratamento em caso de falha na criacao do processo (funcao fork() retornaria -1)
                cerr << "ERRO!"<<endl;
                exit(1);//encerrando 'processo' com falha
            }
            else if(processIdentifier == 0){//com o novo processo gerado através do comando fork() o identificador deste passa a ser 0
                sleep(30);/*estabelecendo temporizador em segundos (1 segundo correspondendo a 1 ano na simulacao) para 
            para dar sequencia no processo*/
                cout << "Nasceu o primeiro bisneto!" << endl;
                cout << "ID do filho: " << getpid()<< endl;// funcao getpid() retorna o identificador ID do processo
                cout << "ID do pai: " << getppid() << endl << endl;// funcao getppid() retorna o identificador ID do criador (pai) do processo
                sleep(12);/*estabelecendo temporizador em segundos (1 segundo correspondendo a 1 ano na simulacao) para 
            para dar sequencia no processo*/
                cout<< "O primeiro bisneto faleceu aos 12 anos\nID do neto:" << getpid()<< endl<<endl;//Morte do primeiro  bisneto e exibicao da sua ID
                exit(0);//encerramento do processo correspondente ao bisneto
            }
            sleep(35);/*estabelecendo temporizador em segundos (1 segundo correspondendo a 1 ano na simulacao) para 
            para dar sequencia no processo*/
            cout<< "O primeiro neto faleceu aos 35 anos\nID do neto:" << getpid()<< endl<<endl;//Morte do primeiro neto e exibicao da sua ID
            exit(0);//encerramento do processo do primeiro neto
        }
        sleep(61);/*estabelecendo temporizador em segundos (1 segundo correspondendo a 1 ano na simulacao) para 
            para dar sequencia no processo*/
        cout<< "O primeiro filho faleceu aos 61 anos\nID do filho:" << getpid()<< endl<<endl;//Morte do primeiro filho e exibicao da sua ID
        exit(0);//encerramento do processo do primeiro filho
    }
    else{
        cout << "Nasceu o pai! ID = " << getpid() << endl << endl;//Nascimento do pai e exibicao de sua ID
        processIdentifier = fork(); // criacao do processo do segundo filho
        if(processIdentifier < 0){// tratamento em caso de falha na criacao do processo (funcao fork() retornaria -1)
            cerr << "ERRO!"<<endl;
            exit(1);//encerrando 'processo' com falha
        }
        else if(processIdentifier == 0){//com o novo processo gerado através do comando fork() o identificador deste passa a ser 0
            sleep(25);
            cout << "Nasceu o segundo filho!" << endl;
            cout << "ID do filho: " << getpid()<< endl;
            cout << "ID do pai: " << getppid() << endl << endl;
            processIdentifier = fork();//criacao do processo do segundo neto
            if(processIdentifier < 0){// tratamento em caso de falha na criacao do processo (funcao fork() retornaria -1)
                cerr << "ERRO!"<<endl;
                exit(1);//encerrando 'processo' com falha
            }
            else if(processIdentifier == 0){//com o novo processo gerado através do comando fork() o identificador deste passa a ser 0
                sleep(20);/*estabelecendo temporizador em segundos (1 segundo correspondendo a 1 ano na simulacao) para 
                para dar sequencia no processo*/
                cout << "Nasceu o segundo neto!" << endl;
                cout << "ID do filho: " << getpid()<< endl;// funcao getpid() retorna o identificador ID do processo
                cout << "ID do pai: " << getppid() << endl << endl;// funcao getppid() retorna o identificador ID do criador (pai) do processo
                sleep(33);/*estabelecendo temporizador em segundos (1 segundo correspondendo a 1 ano na simulacao) para 
                para dar sequencia no processo*/
                cout<< "O segundo neto faleceu aos 33 anos\nID do neto:" << getpid()<< endl<<endl;//Morte do segundo neto e exibicao da sua ID
                exit(0);//encerramento do processo do segundo neto
            }
            sleep(55);/*estabelecendo temporizador em segundos (1 segundo correspondendo a 1 ano na simulacao) para 
            para dar sequencia no processo*/
            cout<< "O segundo filho faleceu aos 55 anos\nID do filho:" << getpid()<< endl<< endl;//Morte do segundo filho e exibicao da sua ID
            exit(0);//encerramento do processo do segundo filho
        }
        processIdentifier = fork(); // criacao do processo do terceiro filho
        if(processIdentifier < 0){// tratamento em caso de falha na criacao do processo (funcao fork() retornaria -1)
            cerr << "ERRO!"<<endl;
            exit(1);//encerrando 'processo' com falha
        }
        else if(processIdentifier == 0){
            sleep(32);/*estabelecendo temporizador em segundos (1 segundo correspondendo a 1 ano na simulacao) para 
            para dar sequencia no processo*/
            cout << "Nasceu o terceiro filho!" << endl;
            cout << "ID do filho: " << getpid()<< endl;// funcao getpid() retorna o identificador ID do processo
            cout << "ID do pai: " << getppid() << endl << endl;// funcao getppid() retorna o identificador ID do criador (pai) do processo
            sleep(55);/*estabelecendo temporizador em segundos (1 segundo correspondendo a 1 ano na simulacao) para 
            para dar sequencia no processo*/
            cout<< "O terceiro filho faleceu aos 55 anos\nID do filho:" << getpid()<< endl<< endl;//Morte do terceiro filho e exibicao da sua ID
            exit(0);//encerramento do processo do terceiro filho
        }
        sleep(90);/*estabelecendo temporizador em segundos (1 segundo correspondendo a 1 ano na simulacao) para 
            para dar sequencia no processo*/
        cout<< "Pai faleceu aos 90 anos\nID do pai:" << getpid()<< endl<< endl;//Morte do pai e exibicao da sua ID
        exit(0);//encerramento do processo do Pai e fim do programa
    }
}
