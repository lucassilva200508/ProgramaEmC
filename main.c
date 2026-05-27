// Grupo: Gean Carlos Sousa Ferreira(RA: 1726100876), Manuela de Cassia Ferreira e Silva(Ra: 926108035),
// Luiz Gustavo Torrez Suxo(RA:926111561), Lucas da Silva Pereira (RA: 926107072), Gabriel Moreira de Oliveira(RA: 926109975),
// Gabriel Couto Fama(RA: 926102609), Gabriel Guide Dias(RA: 926108044), Daniel soares dos Santos(RA: 926104176),
// Rafael Yudi de Lima(RA: 926101976),Karine Moraes Vieira(RA: 926115146)

#include <stdio.h>
#include <stdlib.h>
#include <string.h> 
#include <unistd.h>

// --- FUNÇÃO DE VERIFICAÇÃO DE LOGIN ---
// Recebe o email e a senha cadastrados para comparar com o que o usuário digitar no login.
int Verificar(char email[31], char senha[16]){
    char emailVerif[31], senhaVerif[16];
    int check = 0, escolha2, c;
    int permissao = 0; // 0 = Negado, 1 = Aprovado
    
    // Loop que mantém o usuário na tela de login até ele acertar ou decidir voltar ao menu principal
    while(check == 0){
        system("clear"); 
        
        printf("Digite seu email: ");
        fgets(emailVerif, sizeof(emailVerif), stdin);
        emailVerif[strcspn(emailVerif, "\n")] = '\0'; // Remove o "Enter" (\n) do final da string
        
        printf("\nDigite sua senha: ");
        fgets(senhaVerif, sizeof(senhaVerif), stdin);
        senhaVerif[strcspn(senhaVerif, "\n")] = '\0';
        
        // Compara se o email e senha digitados são iguais aos cadastrados
        if(strcmp(email, emailVerif) == 0 && strcmp(senha, senhaVerif) == 0){
            permissao = 1; // Acesso concedido
            check = 1;     // Sai do loop de verificação
        } else {
            // Caso erre os dados, oferece a opção de tentar novamente ou voltar
            printf("\nSenha ou email incorreto!\n");
            printf("1 - Tentar novamente\n");
            printf("2 - Voltar ao menu\n");
            printf("Escolha uma opção: ");
            scanf("%d", &escolha2);
            
            // Limpa o buffer do teclado para evitar que o "Enter" do scanf seja lido pelo próximo fgets
            while ((c = getchar()) != '\n' && c != EOF);
            
            if(escolha2 == 2){
              check = 1;     // Quebra o loop para voltar ao menu
              permissao = 0; // Mantém a permissão negada
            }
        }
    }
    return permissao; // Retorna 1 se logou com sucesso, ou 0 se falhou/desistiu
}

// --- FUNÇÃO PRINCIPAL ---
int main(){
    int encerrar = 0, escolha, permissao = 0;
    int contaCriada = 0; // Flag para garantir que o usuário não tente logar sem ter uma conta
    
    // Variáveis para armazenar os dados do usuário
    char nome[41], email[31], cpf[12], telefone[12], senha[16];

    // Laço principal que mantém o programa rodando até o usuário escolher a opção de Sair (3)
    do {
        system("clear");
        printf("--------Bem-vindo!--------\n");
        printf("1 - Criar conta\n");
        printf("2 - Login\n");
        printf("3 - Sair\n");
        printf("Escolha uma opção(1 a 3): ");
        scanf("%d", &escolha);
        
        int c;
        while ((c = getchar()) != '\n' && c != EOF);

        // --- OPÇÃO 1: CRIAR CONTA ---
        if(escolha == 1){
            system("clear"); 
            
            printf("Digite seu nome completo: ");
            fgets(nome, sizeof(nome), stdin);
            nome[strcspn(nome, "\n")] = '\0';
            
            printf("\nDigite seu email: ");
            fgets(email, sizeof(email), stdin);
            email[strcspn(email, "\n")] = '\0';
            
            printf("\nCrie sua senha(até 15 dígitos): ");
            fgets(senha, sizeof(senha), stdin);
            senha[strcspn(senha, "\n")] = '\0';
            
            printf("\nDigite seu CPF(sem '.' e '-'): ");
            fgets(cpf, sizeof(cpf), stdin);
            cpf[strcspn(cpf, "\n")] = '\0';
            
            printf("\nDigite seu telefone(apenas os números): ");
            fgets(telefone, sizeof(telefone), stdin);
            telefone[strcspn(telefone, "\n")] = '\0';
            
            printf("\nConta criada com sucesso!\n");
            contaCriada = 1; // Atualiza a variável indicando que agora existe uma conta cadastrada
            sleep(2);
            
        // --- OPÇÃO 2: FAZER LOGIN ---
        } else if(escolha == 2){
            
            // Impede o acesso caso nenhuma conta tenha sido criada no passo 1
            if(contaCriada == 0){
                printf("\nVocê precisa criar uma conta primeiro!\n");
                sleep(2);
            } else {
                // Chama a função de verificação passando os dados originais do cadastro
                permissao = Verificar(email, senha);
                
                // Se a função retornar 1, o login foi um sucesso
                if(permissao == 1){
                    int deslogar = 0;
                    int escolhaLogado;
                    
                    // Laço secundário: Este é o menu interno (Área do usuário logado)
                    do {
                        system("clear");
                        printf("-------- ÁREA LOGADA --------\n");
                        printf("Ola, %s!\n\n", nome);
                        printf("1 - Ver meus dados\n");
                        printf("2 - Acessar loja\n");
                        printf("3 - Deslogar (Voltar ao início)\n");
                        printf("Escolha uma opção: ");
                        scanf("%d", &escolhaLogado);
                        
                        while ((c = getchar()) != '\n' && c != EOF);
                        
                        // Sub-menu 1: Exibe os dados que foram cadastrados
                        if(escolhaLogado == 1){
                            system("clear");
                            printf("--- MEUS DADOS ---\n");
                            printf("Nome: %s\n", nome);
                            printf("Email: %s\n", email);
                            printf("CPF: %s\n", cpf);
                            printf("Telefone: %s\n", telefone);
                            
                            printf("\nPressione [ENTER] para voltar...");
                            getchar(); // Pausa o programa até o usuário pressionar Enter
                            
                        // Sub-menu 2: Mostra o link do projeto
                        } else if(escolhaLogado == 2){
                            system("clear");
                            printf("Link para acessar a loja -> https://danielsoaresdesantos-dot.github.io/petclub1/\n");
                            
                            printf("\nPressione [ENTER] para voltar...");
                            getchar();
                            
                        // Sub-menu 3: Faz o "logout"
                        } else if(escolhaLogado == 3){
                            printf("\nDeslogando...\n");
                            sleep(2);
                            deslogar = 1; // Altera a flag para quebrar o loop da área logada
                            permissao = 0; // Reseta a permissão de segurança
                        } else {
                            printf("\nOpção inválida!\n");
                            sleep(2);
                        }
                        
                    } while(deslogar == 0); // Fica preso nesse menu interno até o usuário pedir para deslogar
                }
            }
            
        // --- OPÇÃO 3: SAIR DO PROGRAMA ---
        } else if(escolha == 3){
            system("clear");
            printf("Saindo...\n");
            sleep(2);
            encerrar = 1; // Altera a flag principal, encerrando o programa
        } else {
            printf("Opção inválida!\n");
            sleep(2);
        }
        
    } while(encerrar == 0); // Repete o menu principal até 'encerrar' ser igual a 1

    system("clear");
    printf("\nPrograma encerrado!\n");
    return 0;
}