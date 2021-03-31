#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>
#include <stdbool.h>
#include <ctype.h>


struct aluno { // Objeto aluno
	char nomeAluno[50];
	char dataNascimento[11];
	int id;
	//Acrescentar mais variáveis
};

struct livro { //Objeto livro
	char nomeLivro[50];
	int isbn;
	char categoria[30];
	int codigo;
  int idAluno;
  int idLivro;
	int dia;
	int mes;
	int ano;
//Acrescentar mais variáveis

};


int main(void) {
	//declaração das funções
	
	//funcões aluno
  void cadastrarAluno(struct aluno *alunos, int *contAluno, int *idAluno);
  void listarAlunos(struct aluno *alunos, int contAluno);
  void buscarAluno(struct aluno *alunos, int contAluno);
  void excluirAluno(struct aluno *a, int *contAlunos);
  
  //funções livro
  void cadastrarLivro (struct livro *lv, int *contLivro, int *idLivro);
	void listarLivros(struct livro *lv, int contLivros);
  void excluirLivro(struct livro *livros, int *contLivro);

  //criando objetos aluno e livro
	struct aluno alunos[100]; //max de usuarios alunos que podem ser cadastrados
	struct livro livros[1000]; //maximo de livros que podem ser cadastrados

	int escolha = -1;
	int contAluno = 0;
	int contLivro = 0;
	int idAluno = 0;
  int idLivro = 1;


  do{ //Loop menu principal

    system("clear");
		printf("\n============== CONTROLE DE BIBLIOTECA ==============\n\n");
		printf("Escolha uma das opções abaixo: \n \n");
		printf("1 - Gerenciar Alunos \n\n");
		printf("2 - Gerenciar Livros \n\n");
		printf("3 - Emprestimo de Livros \n\n");
		printf("4 - Importar / Exportar Dados \n\n");
		printf("0 - Sair \n\n");
		scanf("%d", &escolha);

    switch (escolha) {
      
      case 1:  //MENU ALUNOS
        
        do{

          system("clear");
          printf("\n============ GERENCIAR ALUNOS ============\n\n");
          printf("Escolha um dos itens abaixo: \n \n");
          printf("1 - Cadastrar aluno \n\n");
          printf("2 - Listar alunos \n\n");
          printf("3 - Buscar alunos \n\n");
          printf("4 - Excluir aluno \n\n");
          printf("0 - Voltar \n\n");
          scanf("%d", &escolha);
          
          switch (escolha){
            
            case 0: 
              //sair 
            break;

            case 1: //CADASTRO
              cadastrarAluno(alunos, &contAluno, &idAluno); 
            break;

            case 2: // LISTAGEM
              listarAlunos(alunos, contAluno);
            break;

            case 3: // BUSCAR
              buscarAluno(alunos, contAluno);
            break;
            
            case 4: // EXCLUSÃO
              excluirAluno(alunos, &contAluno);
            break;

            default:
              printf("Escolha invalida!");

          }
        } while(escolha != 0); 
        escolha = -1; 
      break;


      case 2: //MENU LIVROS
        
        do{
          system("clear");
          printf("\n============ GERENCIAR LIVROS ============\n\n");
          printf("Escolha uma dos itens abaixo: \n \n");
          printf("1 - Cadastrar Livro \n\n");
          printf("2 - Listar Livros \n\n");
          printf("3 - Buscar Livro \n\n");
          printf("4 - Excluir Livro \n\n");
          printf("0 - Voltar \n\n");
          scanf("%d", &escolha);
          
          switch (escolha){

            case 1: //CADASTRO
              cadastrarLivro(livros, &contLivro, &idLivro);
            break;

            case 2: //LISTAR
              listarLivros(livros, contLivro);
            break;
            
            case 3: //BUSCAR
              //falta fazer a função buscarLivro()
            break;

            case 4: //EXCLUIR
              excluirLivro(livros, &contLivro);
            break;

            case 0: //SAIR
            break;

            default:
              printf("Escolha invalida!");
          }

        } while(escolha != 0); 
        escolha = -1;
      break;


      case 3: //EMPRESTIMOS - A ser implementado
       
        do{
          switch (escolha){

            case 1: //EMPRESTAR
            break;

            case 2: //DEVOLVER
            break;
            
            case 3: //CONSULTAR
            break;

            default:
              printf("Escolha invalida!");
          }
        } while(escolha != 0); 
      break;
      

      case 4:  //IMPORTAR - EXPORTAR TXT
        do{
          switch (escolha){

            case 1: //GRAVAR EM ARQUIVO
            break;

            case 2: //LER DO ARQUIVO
            break;

          }
        }while (escolha != 0);
      break;

      case 0:
      break;

      default:
      printf("Escolha invalida!");
   
    }
    
  }while(escolha != 0);

}


void cadastrarAluno(struct aluno *alunos, int *contAluno, int *idAluno) {
	system("clear");
	printf("\n============== CADASTRO DE ALUNOS ==============\n\n");
	printf("Nome: ");
	getchar();
 	fgets(alunos[*contAluno].nomeAluno, 50, stdin); 
	alunos[*contAluno].nomeAluno[strcspn(alunos[*contAluno].nomeAluno, "\n")] = 0;
	printf("\n");
	printf("Data de Nascimento: ");
	scanf("%s", alunos[*contAluno].dataNascimento); 
	*idAluno = *idAluno + 1;
  alunos[*contAluno].id = *idAluno; 
  *contAluno = *contAluno +1;
	printf("\n\nAluno cadastrado com sucesso!\n");
  printf("\n==============================================\n\n");
  printf("\n\nPressione ENTER para voltar.\n");
	getchar();
	getchar();
	system("clear");

}

/*************************************************************************
************************************************************************/

void listarAlunos(struct aluno *alunos, int contAluno) {
  system("clear");
	printf("\n=============== LISTA DE ALUNOS ===============\n\n");
	for (int i=0; i < contAluno; i++) {
		printf("ID: ");
		printf("%d", alunos[i].id);
		printf(" | ");
		printf("%s", alunos[i].nomeAluno);
		printf(" | ");
		printf("%s", alunos[i].dataNascimento);
		printf("\n");
	}
	printf("\n\nFim da listagem. Mostrando %d resultado(s) encontrado(s).\n", contAluno);
  printf("\n==============================================\n\n");
	printf("\n\nPressione ENTER para voltar.\n");
	getchar();
	getchar();
	system("clear");
}

/*************************************************************************
************************************************************************/

void buscarAluno(struct aluno *alunos, int contAluno) {
  system("clear");
  char *resp;
  char busca[50];
  int result = 0;
  printf("\n=============== BUSCAR ALUNOS ===============\n\n");
	printf("Digite a palavra: ");
	scanf("%s", busca);
  printf("\n\n");
  for(int i = 0; i < contAluno; i++){
    
    resp = strstr(alunos[i].nomeAluno, busca);
    if (resp != NULL) {
      printf("ID: ");
      printf("%d", alunos[i].id);
      printf(" | ");
      printf("%s", alunos[i].nomeAluno);
      printf(" | ");
      printf("%s", alunos[i].dataNascimento);
      printf("\n");
      result++;
    }
  }
  if(result == 0)
    printf("Nenhum resultado encontrado.");
  else 
    printf("\n\nFim da busca. Mostrando %i resultado(s) encontrado(s).\n", result);
  printf("\n==============================================\n\n");
	printf("\n\nPressione ENTER para voltar.\n");
	getchar();
	getchar();
	system("clear");

}


/*************************************************************************
************************************************************************/



void excluirAluno(struct aluno *alunos, int *contAluno) {
	system("clear");
  int i=0, id = 0; 
	bool flag = true;
	printf("\n=============== REMOVER ALUNOS ===============\n\n");
	printf("Digite o ID do aluno: ");
	scanf("%d", &id);
  char nome[50];
		while(flag) {

      if (alunos[i].id == id) { //procura o id em todas as posições do vetor aluno[]	
        strcpy(nome, alunos[i].nomeAluno); // salvando nome do aluno pra imprimir depois
        for (int j = i; j < *contAluno; j++) //quando encontra, faz um for da posição encontrada até o final
					alunos[j] = alunos[j+1]; //desce cada um dos alunos de posição, da posição encontrada até o final 
        
        flag = false;	//já achou e já removeu, agora tem que sair do while
        *contAluno = *contAluno - 1;	//sinaliza que tem 1 aluno a menos na lista
        printf("\n%s removido com sucesso!\n", nome);
        printf("\n==============================================\n\n");
        printf("\n\nPressione ENTER para voltar.\n");
        getchar();
        getchar();
        system("clear");

			}else 
        if (i == *contAluno) { // chegou ao final da lista sem encontrar o aluno
          flag = false;
          printf("\nID invalido. \n");
          printf("\n==============================================\n\n");
          printf("\n\nPressione ENTER para voltar.\n");
          getchar();
          getchar();
          system("clear");
        }
			i++;
		}
}

/*************************************************************************
*********************************************************************** */

void cadastrarLivro (struct livro *lv, int *contLivro, int *idLivro) {
  system("clear");
	printf("\n============== CADASTRO DE LIVROS ==============\n\n");
	printf("Nome: ");
  getchar();
	fgets(lv[*contLivro].nomeLivro, 50, stdin);
	printf("COD.: ");
	scanf("%d", &lv[*contLivro].codigo);
	lv[*contLivro].nomeLivro[strcspn(lv[*contLivro].nomeLivro, "\n")] = 0;
	printf("\n");
	printf("ISBN: ");
	scanf("%d", &lv[*contLivro].isbn);
	printf("\n");
	printf("Categoria: ");
	scanf("%s",lv[*contLivro].categoria);
	printf("\n\nLivro cadastrado com sucesso!\n");
  printf("\n==============================================\n\n");
  printf("\n\nPressione ENTER para voltar.\n");
	getchar();
	getchar();
	system("clear");
  lv[*contLivro].idLivro = *idLivro;
	lv[*contLivro].idAluno = -1; //id do aluno que pegou este livro. A ser setado na função empréstimo
	lv[*contLivro].dia = -1; //data que pegou o livro
	lv[*contLivro].mes = -1;
	lv[*contLivro].ano = -1;
   *contLivro = *contLivro + 1;
   *idLivro = *idLivro +1;

}

/*************************************************************************
*********************************************************************** */

void listarLivros(struct livro *lv, int contLivro) {
  system("clear");
	printf("\n================ LISTA DE LIVROS ================\n\n");
	for (int i=0; i < contLivro; i++) {
		printf("ID: ");
		printf("%d", lv[i].idLivro);
    printf("ISBN: ");
		printf("%d", lv[i].isbn);
		printf(" | ");
		printf("%s", lv[i].nomeLivro);
		printf(" | ");
		printf("%s", lv[i].categoria);
		printf(" | ");
		if (lv[i].idAluno != -1)
			printf("Emprestado");
		else
			printf("Disponivel");   

		printf("\n");
	}
	printf("\n\nFim da listagem. Mostrando %d resultado(s) encontrado(s).\n", contLivro);
  printf("\n==============================================\n\n");
	printf("\n\nPressione ENTER para voltar.\n");
	getchar();
	getchar();
	system("clear");
}

void excluirLivro(struct livro *livros, int *contLivro ){
	int i = 0, j = 0, id;
	bool loop = true;
  char nome[50];
  system("clear");
	printf("\n================== REMOVER LIVROS ==================\n\n");
	printf("Digite o id do livro: ");
	scanf("%d", &id);

	do{
	  if(livros[i].idLivro == id) {
      strcpy(nome, livros[i].nomeLivro);
		  for (int j = i; j < *contLivro; j++) //quando encontra, faz um for da posição encontrada até o final
			  livros[j] = livros[j+1]; //desce cada um dos alunos de posição, da posição encontrada até o final
			
      loop = false;	//já achou e já removeu, agora tem que sair do while
			*contLivro = *contLivro - 1;	//registra que tem 1 livro a menos na lista           
			printf("\nLivro %s removido com sucesso!. \n", nome);
      printf("\n==============================================\n\n");
      printf("\n\nPressione ENTER para voltar.\n");
			getchar();
			getchar();
			system("clear");

		}else 
      if (i == *contLivro) { // chegou ao final da lista sem encontrar o livro
				loop = false; 
				printf("\n Id invalido. \n");
        printf("\n==============================================\n\n");
        printf("\n\nPressione ENTER para voltar.\n");
				getchar();
				getchar();
				system("clear");
			}
		i++;
	}while(loop);
}

/*************************************************************************
************************************************************************/

void emprestarLivro() {

}

/*************************************************************************
************************************************************************/

void devolverLivro(int idLivro) {
  
}

/*************************************************************************
************************************************************************/

void livrosDisponivels(){

}

/*************************************************************************
************************************************************************/

void livrosEmprestados (){

}


/*************************************************************************
************************************************************************/

void devolucaoAtrasada() {

}


/*************************************************************************
************************************************************************/

void importarArquivo() {

}

/*************************************************************************
************************************************************************/
void exportarArquivo() {
  
}

/*************************************************************************
************************************************************************/


