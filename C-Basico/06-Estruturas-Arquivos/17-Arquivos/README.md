# Aula 17: Arquivos

## Objetivos da Aula
- Compreender o conceito de arquivos em C
- Aprender a abrir, ler, escrever e fechar arquivos
- Entender diferentes modos de abertura de arquivos
- Dominar operações com arquivos de texto e binários
- Aplicar arquivos em situações práticas

## Teoria

### O que são Arquivos?
Arquivos são estruturas de dados persistentes que permitem armazenar informações de forma permanente. Em C, arquivos são tratados como sequências de bytes que podem ser:
- **Arquivos de Texto**: Contêm caracteres legíveis
- **Arquivos Binários**: Contêm dados em formato binário

### Tipos de Arquivos

#### Arquivos de Texto
- Contêm caracteres ASCII
- Legíveis por humanos
- Podem ser editados em editores de texto
- Exemplos: .txt, .c, .h

#### Arquivos Binários
- Contêm dados em formato binário
- Não são legíveis diretamente
- Mais eficientes para dados estruturados
- Exemplos: .exe, .obj, arquivos de dados

### Ponteiro FILE
O tipo `FILE` é uma estrutura que contém informações sobre o arquivo:
```c
FILE *arquivo;
```

### Modos de Abertura de Arquivos

#### Modos para Arquivos de Texto
```c
"r"   // Leitura (read) - arquivo deve existir
"w"   // Escrita (write) - cria novo arquivo ou sobrescreve
"a"   // Anexar (append) - adiciona ao final do arquivo
"r+"  // Leitura e escrita - arquivo deve existir
"w+"  // Leitura e escrita - cria novo arquivo
"a+"  // Leitura e anexar - cria se não existir
```

#### Modos para Arquivos Binários
```c
"rb"  // Leitura binária
"wb"  // Escrita binária
"ab"  // Anexar binário
"rb+" // Leitura e escrita binária
"wb+" // Leitura e escrita binária (cria novo)
"ab+" // Leitura e anexar binário
```

### Funções Básicas de Arquivos

#### 1. fopen() - Abrir Arquivo
```c
FILE *fopen(const char *nome, const char *modo);
```
**Exemplo:**
```c
FILE *arquivo = fopen("dados.txt", "w");
if (arquivo == NULL) {
    printf("Erro ao abrir arquivo!\n");
    return 1;
}
```

#### 2. fclose() - Fechar Arquivo
```c
int fclose(FILE *arquivo);
```
**Exemplo:**
```c
fclose(arquivo);
```

#### 3. fgetc() - Ler Caractere
```c
int fgetc(FILE *arquivo);
```
**Exemplo:**
```c
char c = fgetc(arquivo);
while (c != EOF) {
    printf("%c", c);
    c = fgetc(arquivo);
}
```

#### 4. fputc() - Escrever Caractere
```c
int fputc(int caractere, FILE *arquivo);
```
**Exemplo:**
```c
fputc('A', arquivo);
```

#### 5. fgets() - Ler String
```c
char *fgets(char *string, int tamanho, FILE *arquivo);
```
**Exemplo:**
```c
char linha[100];
while (fgets(linha, sizeof(linha), arquivo) != NULL) {
    printf("%s", linha);
}
```

#### 6. fputs() - Escrever String
```c
int fputs(const char *string, FILE *arquivo);
```
**Exemplo:**
```c
fputs("Olá, mundo!\n", arquivo);
```

#### 7. fprintf() - Escrever Formatado
```c
int fprintf(FILE *arquivo, const char *formato, ...);
```
**Exemplo:**
```c
fprintf(arquivo, "Nome: %s, Idade: %d\n", nome, idade);
```

#### 8. fscanf() - Ler Formatado
```c
int fscanf(FILE *arquivo, const char *formato, ...);
```
**Exemplo:**
```c
fscanf(arquivo, "%s %d", nome, &idade);
```

### Funções para Arquivos Binários

#### 1. fread() - Ler Dados Binários
```c
size_t fread(void *ptr, size_t tamanho, size_t count, FILE *arquivo);
```
**Exemplo:**
```c
int numeros[10];
fread(numeros, sizeof(int), 10, arquivo);
```

#### 2. fwrite() - Escrever Dados Binários
```c
size_t fwrite(const void *ptr, size_t tamanho, size_t count, FILE *arquivo);
```
**Exemplo:**
```c
int numeros[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
fwrite(numeros, sizeof(int), 10, arquivo);
```

### Funções de Posicionamento

#### 1. fseek() - Posicionar no Arquivo
```c
int fseek(FILE *arquivo, long offset, int origem);
```
**Origens:**
- `SEEK_SET` - Início do arquivo
- `SEEK_CUR` - Posição atual
- `SEEK_END` - Fim do arquivo

**Exemplo:**
```c
fseek(arquivo, 0, SEEK_SET);  // Ir para o início
fseek(arquivo, 10, SEEK_CUR); // Avançar 10 bytes
fseek(arquivo, -5, SEEK_END); // 5 bytes antes do fim
```

#### 2. ftell() - Obter Posição Atual
```c
long ftell(FILE *arquivo);
```
**Exemplo:**
```c
long posicao = ftell(arquivo);
printf("Posição atual: %ld\n", posicao);
```

#### 3. rewind() - Voltar ao Início
```c
void rewind(FILE *arquivo);
```
**Exemplo:**
```c
rewind(arquivo);
```

### Funções de Verificação

#### 1. feof() - Verificar Fim do Arquivo
```c
int feof(FILE *arquivo);
```
**Exemplo:**
```c
while (!feof(arquivo)) {
    char c = fgetc(arquivo);
    printf("%c", c);
}
```

#### 2. ferror() - Verificar Erro
```c
int ferror(FILE *arquivo);
```
**Exemplo:**
```c
if (ferror(arquivo)) {
    printf("Erro na operação do arquivo!\n");
    clearerr(arquivo);
}
```

### Manipulação de Arquivos com Estruturas

#### Escrever Estrutura
```c
struct Pessoa pessoa = {"João", 25, 1.75};
fwrite(&pessoa, sizeof(struct Pessoa), 1, arquivo);
```

#### Ler Estrutura
```c
struct Pessoa pessoa;
fread(&pessoa, sizeof(struct Pessoa), 1, arquivo);
```

### Arquivos Temporários

#### tmpfile() - Criar Arquivo Temporário
```c
FILE *tmpfile(void);
```
**Exemplo:**
```c
FILE *temp = tmpfile();
if (temp != NULL) {
    fprintf(temp, "Dados temporários\n");
    fclose(temp);
}
```

### Verificação de Existência de Arquivos

#### access() - Verificar Permissões
```c
#include <unistd.h>
int access(const char *caminho, int modo);
```
**Exemplo:**
```c
if (access("arquivo.txt", F_OK) == 0) {
    printf("Arquivo existe!\n");
}
```

### Tratamento de Erros

#### Verificações Importantes
```c
// Verificar se arquivo foi aberto
if (arquivo == NULL) {
    perror("Erro ao abrir arquivo");
    return 1;
}

// Verificar se operação foi bem-sucedida
if (fprintf(arquivo, "dados") < 0) {
    printf("Erro na escrita!\n");
}

// Verificar fim do arquivo
if (feof(arquivo)) {
    printf("Fim do arquivo atingido\n");
}
```

### Boas Práticas

#### 1. Sempre Verificar Erros
```c
FILE *arquivo = fopen("dados.txt", "r");
if (arquivo == NULL) {
    perror("Erro ao abrir arquivo");
    return 1;
}
```

#### 2. Sempre Fechar Arquivos
```c
FILE *arquivo = fopen("dados.txt", "w");
// ... operações ...
fclose(arquivo);
```

#### 3. Usar Buffering Adequado
```c
// Para arquivos grandes
char buffer[1024];
while (fgets(buffer, sizeof(buffer), arquivo) != NULL) {
    // Processar buffer
}
```

#### 4. Verificar Operações de I/O
```c
if (fprintf(arquivo, "dados") < 0) {
    printf("Erro na escrita!\n");
}
```

## Exemplos Práticos

### Exemplo 1: Operações Básicas com Arquivos
Demonstra abertura, leitura, escrita e fechamento de arquivos.

### Exemplo 2: Arquivos com Estruturas
Mostra como trabalhar com estruturas em arquivos.

### Exemplo 3: Manipulação Avançada
Ilustra operações complexas com arquivos.

## Exercícios

### Exercício 1: Sistema de Arquivos Simples
Crie um sistema que gerencie arquivos de texto com operações básicas.

### Exercício 2: Banco de Dados em Arquivo
Implemente um sistema de banco de dados simples usando arquivos.

### Exercício 3: Editor de Texto Básico
Crie um editor de texto básico com funcionalidades de leitura e escrita.

## Conceitos Importantes

### Vantagens dos Arquivos
1. **Persistência**: Dados permanecem após fechar o programa
2. **Organização**: Estrutura hierárquica de informações
3. **Compartilhamento**: Múltiplos programas podem acessar
4. **Eficiência**: Acesso direto a dados específicos

### Cuidados com Arquivos
1. **Sempre fechar**: Evitar vazamentos de recursos
2. **Verificar erros**: Tratar falhas de I/O
3. **Permissões**: Verificar acesso aos arquivos
4. **Concorrência**: Cuidado com acesso simultâneo

### Boas Práticas
1. Sempre verificar se arquivo foi aberto com sucesso
2. Fechar arquivos após uso
3. Usar modos apropriados para cada operação
4. Tratar erros adequadamente
5. Usar buffering para melhor performance

## Próximos Passos
Na próxima aula, aprenderemos sobre:
- Projeto final integrando todos os conceitos
- Aplicação completa usando estruturas e arquivos
- Desenvolvimento de sistema completo

## Resumo
- Arquivos permitem persistência de dados
- FILE* é o ponteiro para arquivos
- Diferentes modos para diferentes operações
- Funções específicas para texto e binário
- Sempre verificar erros e fechar arquivos
- Estruturas podem ser salvas/recuperadas 