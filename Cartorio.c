#include <stdio.h>  //biblioteca de comunicação com o usuário
#include <stdlib.h> //biblioteca de alocação de espaço em memória
#include <locale.h> //biblioteca associada a "língua" do texto por região
#include <string.h> //biblioteca responsável pelo gerenciamento de strings


int registrar()
{
    char arquivo[50]; //Criando uma string de 40 caracteres
    char cpf[50];
    char nome[50];
    char sobrenome[50];
    char cargo[50];

    printf("Digite o CPF a ser cadastrado: ");
    scanf("%s", cpf);

    strcpy(arquivo, cpf); //copiar informações de uma str para outra (cpf --> arquivo)

    FILE *file; //funão "FILE" usada para criar um "file" (arquivo)
    file = fopen(arquivo,"w"); //abre o arquivo no modo escrita "w"
    fprintf(file, " --> CPF: ");
    fprintf(file, cpf); //responsável por salvar a informação (cpf) dentro do arquivo (file)
    fclose(file); //fecha o arquivo que foi aberto ("fopen")
    
    //Trecho para adicionar uma vírgula
    file = fopen(arquivo, "a"); //"a" atualiza as informações do arquivo
    fprintf(file, ",");
    fclose(file);

    // Trecho de código para adicionar o nome
    printf("Digite o nome do portador do CPF: ");
    scanf("%s", nome);
    file = fopen(arquivo, "a");
    fprintf(file, " Nome: ");
    fprintf(file, nome);
    fclose(file);

    //Vírgula
    file = fopen(arquivo, "a");
    fprintf(file, ",");
    fclose(file);

    //Trecho para adicionar o sobrenome
    printf("Digite o sobrenome: ");
    scanf("%s", sobrenome);
    file = fopen(arquivo, "a");
    fprintf(file, " Sobrenome: "); // Para deixar mais legível
    fprintf(file, sobrenome);
    fclose(file);

    //Vírgula
    file = fopen(arquivo,"a");
    fprintf(file, ",");
    fclose(file);

    //Trecho para adicionar o cargo
    printf("Digite o cargo referente a essa pessoa: ");
    scanf("%s", cargo);
    file = fopen(arquivo, "a");
    fprintf(file, " Cargo: ");
    fprintf(file, cargo);
    fclose(file);

    system("pause");
    return 0;
    // Retorno simbólico, pois a função é int. Evita o aviso:
    // warning: control reaches end of non-void function [-Wreturn-type] 

}

int buscar()
{
    setlocale(LC_ALL, "Portuguese"); 

    char cpf[50];
    char conteudo[500];

    printf("Digite o CPF a ser consultado:");
    scanf("%s", cpf);

    //Trecho para buscar um CPF
    FILE *file;
    file = fopen(cpf, "r");

    // Validação caso o CPF não seja encontrado
    if(file == NULL)
    {
        printf("\n   ### CPF não encontrado! O arquivo não existe! ### \n\n");
    }

    // Apresentação das informações encontradas no arquivo
    while(fgets(conteudo, 500, file) != NULL)
    {
        printf("\n Essas são as infomações registradas:");
        printf("%s", conteudo);
        printf("\n \n");
    }
    
    system("pause");

    return 0; 
     
}

int deletar()
{
    char cpf[50];

    printf("Digite o CPF do usuário a ser deletado: ");
    scanf("%s", cpf);
    
    remove(cpf); // Para deletar os dados associados ao CPF

    FILE *file;
    file = fopen(cpf, "r");
    fclose(file);

    if(file == NULL)
    {
        printf("As informções deste usuário não estão mais no sistema! \n");
        system("pause");
    }

    return 0;

}

int main()
{
    int option = 0; //Definindo variáveis
    int loop = 1;

    for((loop=1); (loop=1);)
    {

        system("cls"); // Comunicação com o SO (cls - limpa as linhas anteriores)

        setlocale(LC_ALL, "Portuguese"); //LC_ALL está indicando a categoria de texto

        printf("      ***         Cartório da EBAC      ***         \n\n");
        printf("Selecione uma opção: \n\n"); 
        printf("\t I   - Registrar um novo nome\n"); // \t Recuo no texto
        printf("\t II  - Buscar nome\n");
        printf("\t III - Deletar nome\n");
        printf("\t IV  - Sair do sistema\n\n\n");
        printf("Opção: ");

        scanf("%d", &option); //Escaneia o que o usuário digita (& - indica onde armazenar)
                              //(%d - armazena variável inteira)

        system("cls"); // Comunicação com o SO (cls - limpa as linhas anteriores)

        switch(option)
        {
            case 1:
            registrar();
            break;

            case 2:
            buscar();
            break;

            case 3:
            deletar();
            break;

            case 4:
            printf("Obrigado por utilizar o sistema.");
            return 0;
            break;

            default:
            printf("O valor inserido é inválido! \n");
            system("pause");
            break;
        }

    }

}