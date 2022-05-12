# 🥬 Cabbage 🥬

## :book: Descrição
*Cabbage* é um gerenciador de janelas e renderizador 2D de código aberto gravado em C++.

:green_salad: *Cabbage* faz parte do ecossistema *Salad* :green_salad:

## :dart: Objetivo:
Fornecer uma API simples de utilizar na hora de implementar funcionalidades de desenho em programas em C++.

## :gear: Responsabilidades da API:
- 🟥 Controle de janelas e monitores
- 🟥 Desenho
- 🟥 Interação com a janela (*mouse*, teclado e *gamepads*)
- 🟥 Escolha de API gráfica

Legenda - 🟢: Feito 🔶: Em andamento 🟥: Não iniciado

# <a name="dependencias"></a> :books: Dependências:

## 💻 Hardware

- Processador com suporte à arquitetura x86_64
- Placa gráfica compatível com **OpenGL 3.3 Core-Profile**

---

## 🪟 Windows

### 📌 MinGW-w64 (GCC 8.1.0):
Conjunto de ferramentas incluindo `gcc`, `g++` e `make` (compiladores de C, C++ e ferramenta de automatização de construção de aplicações), compatíveis com o padrão C17 e C++17.
- Baixe pelo site oficial: https://www.mingw-w64.org/
- **ou** instale-o pelo Chocolatey: `choco install mingw`

### 📌 Git Bash
Alguns comandos do `makefile` são de sistemas Linux (por exemplo, o comando `find`). Por isso, recomendamos que utilize o Git Bash dado que o mesmo vem com algumas ferramentas necessárias já instaladas;

### 📌 Bibliotecas
- #### **(Opcional)** GLFW 3.3.7: 
  Biblioteca gráfica utilizada para implementar a API. **O projeto já vem com a biblioteca compilada internamente, então não é necessário baixar e reinstalar a biblioteca**. *Caso queira/precise compilar a versão a partir do código fonte*, compile a biblioteca e substitua o arquivo `libglfw3.a` da pasta `external/glfw-3.3.7/lib/win64`. A biblioteca está disponível em https://www.glfw.org.

---

## 🐧 Linux:

### 📌 `gcc`/`g++` (8.1.0) e `make`:
Compiladores de C, C++ e ferramenta de automatização de construção de aplicações. **Geralmente** as distribuições Linux já vêm com as três ferramentas instaladas. **Caso não tenha**, baixe-as do site oficial:
- https://gcc.gnu.org/
- https://www.gnu.org/software/make/

### 📌 Bibliotecas:
- #### `libc` ou `libdl`:
  Bibliotecas utilizadas para carregar outras bibliotecas dinamicamente. **Recomendamos fortemente a instalação da biblioteca pelo seu gerenciador de pacotes, caso não as tenha.**
- #### `libpthread`: 
  Biblioteca para utilização de *threads* POSIX. **Recomendamos fortemente a instalação da biblioteca pelo seu gerenciador de pacotes, caso não a tenha.**
- #### `libGL`: 
  Biblioteca utilizada para implementar a API do OpenGL. **Recomendamos fortemente a instalação da biblioteca pelo seu gerenciador de pacotes, caso não a tenha.**
- #### `libX11` ou `libXrandr`: 
  Biblioteca para gerenciamento de janelas e monitores. **Recomendamos fortemente a instalação da biblioteca pelo seu gerenciador de pacotes, caso não as tenha.**
- #### `libglfw3` (versão 3.3.7): 
  Biblioteca gráfica utilizada para implementar a API. **Recomendamos fortemente a instalação da biblioteca pelo seu gerenciador de pacotes, caso não a tenha.**. O projeto já vem com a biblioteca compilada internamente por uma máquina com o Linux Mint 20.2. *Caso não tenha instalado a biblioteca pelo gerenciador de pacotes ou não possua a versão especificada e caso tenha uma outra distribuição Linux ou queira/precise compilar a versão a partir do código fonte*, compile a biblioteca e substitua o arquivo `libglfw3.a` da pasta `external/glfw-3.3.7/lib/linux`. A biblioteca está disponível em https://www.glfw.org.


## :computer: Executando o projeto:
### A partir do código fonte:
- Garanta que todas as [dependências](#dependencias) estão satisfeitas.
- Execute `make all` (dependendo da versão do MinGW no Windows, use `mingw-w64-x86_64-make.exe all`) para compilar, conectar e criar o executável. Caso tenha alterado algum arquivo após uma primeira execução, o `make all` vai atualizar somente os códigos fonte modificados.
- Execute `./out` para rodar o projeto.
- Execute `make clean` para remover os binários gerados caso queira realizar uma outra compilação.
 
## :busts_in_silhouette: Contribuindo com o projeto
### Caso não seja um colaborador do projeto:
- Crie uma nova [**issue**](https://github.com/Gaizgrol/Cabbage/issues) no projeto.
- Realize um *fork* do projeto no GitHub.
- Faça as alterações necessárias e envie para o seu *fork* com o padrão de commits utilizado no https://gitmoji.dev.
- Crie uma *pull request* para a branch `main` e descreva as alterações realizadas.
- Referencie sua *issue* na *pull request* criada.

## :x: Problemas
- Caso não consiga executar algum comando ou não consiga abrir a janela do projeto, verifique se as dependências foram corretamente instaladas.
- Caso esteja utilizando Windows, verifique se as ferramentas estão incluídas no $PATH da máquina em *Variáveis de Ambiente*
- Caso esteja utilizando Linux, verifique se as ferramentas foram instaladas corretamente e se a versão do GLFW é a 3.3.7
- Caso tenha algum outro erro, sinta-se à vontade para criar uma nova [**issue**](https://github.com/Gaizgrol/Cabbage/issues) no projeto. 

## 🥗 Ecossistema *Salad*:
- 🥬 *Cabbage*: https://github.com/Gaizgrol/Cabbage
- 🥕 *Carrot*: https://github.com/Gaizgrol/Carrot
- 🥦 *Cauliflower*: `// Em breve...`
- 🥒 *Cucumber*: `// Em breve...`
- 🌶️ *Chili*: `// Em breve...`
- 🌽 *Corn*: `// Em breve...`
