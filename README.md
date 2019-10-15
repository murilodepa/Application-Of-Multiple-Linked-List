# Aplicação de Múltipla Lista Ligada

## Projeto que controla uma lista de clientes com pagamentos pendentes de produtos adquiridos numa determinada loja.

### Descrição do Projeto
   * Esse projeto tem o intuito de controlar os pagamentos pendentes de produtos adquiridos numa determinada loja e de aprender e aprimorar os conhecimentos relacionados a lista ligada. O programa contém um menu, que permite o usuário escolher umas das opções desejadas, para cada uma dessas opções foram realizada uma função especificamente, que seria: 1. Compras / 2. Pagamento / 3. Impressão / 4. Sair. Podendo também inserir novos clientes e novos produtos conforme desejado. 
   * A opção número 1, a **Comprar**, solicita o nome do cliente, e faz uma verificação se o cliente já possui cadastro, se caso o cliente possuir, solicita os produtos e os preços e insere no final da lista, atualizando o saldo devedor do cliente. Se o cliente ainda não está cadastrado na loja, além dos produtos e preços, ler também, o endereço do cliente para realizar seu cadastro.  
  * A opção número 2, a **Pagamento**, tem finalidade de ler o nome do cliente e do produto que está sendo pago. Não necessitando digitar nenhum valor, pois foi suposto que o cliente sempre pagará o valor completo do produto. Nessa função é necessário estar encontrando o produto na lista do cliente e excluir o nó, por contra partida, diminuindo do saldo devedor do cliente em relação ao valor pago. Em caso de saldo devedor zero, o cliente continua cadastrado.  
 * A opção 3, **Impressão**, contém um *submenu*, sendo a primeira opção: *1. Lista de Todos os Clientes à Nome, Endereço e Saldo Devedor* e a segunda opção: *2. Consultar um Cliente à Produtos Pendentes de Pagamento (se houver) e Saldo Devedor (mesmo que seja zero)*, imprimindo na tela.
 * A última opção é a de **Sair** do programa. 
* A função *main* nesse programa e na maioria dos outros que foram realizados, ficou praticamente exclusiva para a definição das variáveis do problema, chamada das funções (menu) e pequenas impressões de avisos. 
 
* Abaixo, pode ser observado um exemplo ilustrativo de como irá ficar as ligações e os campos de informações:

![ListaCliente](https://user-images.githubusercontent.com/56207941/66794961-7f25ac00-eed9-11e9-8ed3-04c1d615e4d4.PNG)

*A imagem foi retirada de um PDF, no qual foi proposto esse trabalho, encontrado neste repositório.*

* Na imagem abaixo, pode ser observado o programa em tempo de execução, executando uma simulação de entrada de dados de um cliente:

![multilistaligada](https://user-images.githubusercontent.com/56207941/66795738-e3496f80-eedb-11e9-93be-75eb73e50cbf.PNG)

### Pré-requisitos

#### Sistema Operacional
* Foi utilizado o Windows 10, mas pode ser realizado em outro sistema operacional, necessita instalar o compilador compatível com o sistema operacional.

 #### Compilador
* Foi utilizado o ambiente integrado de desenvolvimento Code::Blocks e a implementação Mingw do GCC (GNU Compiler Collection) como seu compilador.
* <a> [Code::Blocks: Necessário para desenvolvimento do projeto](http://www.codeblocks.org/downloads/26)
  
 #### Bibliotecas
* include <stdio.h>  // "Cabeçalho Padrão de (Entrada/Saída)"
* include <stdlib.h> // "Cabeçalho da Biblioteca de Propósito Geral Padrão"
* #include <conio.h>  // "Usada para a função getch()
* #include <string.h> // String para copiar uma frase em outra e comparaçôes de texto
* #ListaLigada.h //Anexada neste repositório

   * **Observação:** Para desenvolver este projeto, precisa apenas de conhecimentos básicos sobre lógica de programação e linguagem de programação C.

### Guia de instalação
* Para executar o programa na linguagem C, no qual o algoritmo foi realizado, necessita apenas de um compilador e uma IDE que compile e execute essa linguagem de programação, no caso do projeto, foi utilizado o Code::Blocks e o compilador Mingw do GCC como já descrito, não precisando de nenhuma outra ferramenta adicional ou especial, esse programa pode ser obtido no link acima, mas também, pode estar sendo utilizado outros softwares para o desenvolvimento deste projeto ou similar.

### Desenvolvimento
* Git clone https://github.com/murilodepa/Aplicacao-de-Multiplas-Lista-Ligada
* Se realizar "Download ZIP", necessita de um descompactador de arquivos.
* Após ter instalado o Code::Blocks ou outro programa similar, execute-o e selecione "arquivo" e depois "abrir projeto".
* Selecione o diretório onde está salvo o arquivo e depois selecione a opção abrir.
* Logo em seguida, selecione a opção executar e o programa começará a ser executado.

### Contribuições
- Contribuições e possíveis melhorias, no meu ponto de vista são sempre bem-vindas.
