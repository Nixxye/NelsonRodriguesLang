# Nelson Rodrigues Lang

Um compilador para uma linguagem de programação experimental e artística, inspirada no universo dramático e trágico do dramaturgo brasileiro Nelson Rodrigues.

A linguagem utiliza uma sintaxe que emula um roteiro de peça de teatro, com Personagens, Atos, Cenas e diálogos que representam operações de código. O objetivo é explorar a programação como forma de expressão literária.

## Filosofia da Linguagem

* **Sintaxe Teatral:** Comandos são diálogos e estruturas de controle são rubricas, criando um código que se lê como um pequeno ato.
* **Tipos de Dados Dramáticos:** Variáveis numéricas são "Pilhas de Inteiros", refletindo a profundidade e o estado mutável dos personagens. Strings são "Cenários", descrições que podem ser alteradas dinamicamente.
* **Compilado com LLVM:** O compilador traduz o roteiro para LLVM Intermediate Representation (IR), que é então compilado para um executável nativo de alta performance.

## Exemplo de Código

```

A MEMORIA EM CARNE VIVA: A DESOLACAO.

Alaide, uma alma fraturada pela memoria.
(Lembranca, uma rua deserta banhada por uma luz fraca)

ATO I: O DESESPERO.
CENA I:
[ENTRA Alaide]

```
	# O laço representa a ruminação obsessiva de Alaíde.
	ENQUANTO Esta chovendo, Alaide se tortura:

		# CONCATENAÇÃO: Um detalhe vago emerge na lembrança.
		ADICIONE AO CENARIO: No fim da rua um vulto
		
		Alaide: Havia alguem sim havia
		Alaide INICIO MOSTRAR_CENARIO FIM

		# SUBSTITUIÇÃO: A atmosfera da cena se corrompe.
		SE Loira FOR IGUAL A 3, a verdade apodrece:
			SUBSTITUIR CENARIO luz fraca POR escuridao que sufoca NO CENARIO.
		A SENTENÇA FINDA!
        
		# ...
	os questionamentos de Alaide se ENCERRAM.
```

FIM.

````

## Como Compilar o Compilador

### Pré-requisitos
Você precisará ter as seguintes ferramentas instaladas (para sistemas baseados em Debian/Ubuntu):
```bash
sudo apt update
sudo apt install build-essential flex bison clang llvm-dev
````

### Compilação

Com os pré-requisitos instalados, basta usar o Makefile:

```bash
make
```

Isso irá gerar o executável do compilador chamado `nrparser`.

## Como Usar

1.  **Escreva seu roteiro:** Crie um arquivo com seu código, como por exemplo `roteiros/meu_ato.nr`.
2.  **Compile seu roteiro:** Use o `nrparser` para traduzir seu roteiro para LLVM IR. O Makefile simplifica isso:
    ```bash
    # Opcional: para ver o arquivo .ll gerado
    make run
    ```
3.  **Compile e execute o programa final:** Para compilar o LLVM IR e rodar o executável final, use:
    ```bash
    make run-llvm
    ```