# Dev-C++ para Desenvolvimento em C

## 🎯 Visão Geral

O Dev-C++ é um IDE gratuito e completo para desenvolvimento em C/C++. É especialmente popular entre iniciantes devido à sua simplicidade e facilidade de uso.

## 📋 Pré-requisitos

### 1. Instalar Dev-C++
- **Windows**: Baixar do [site oficial](https://sourceforge.net/projects/orwelldevcpp/)
- **Linux**: Usar Wine ou versão alternativa
- **macOS**: Usar versão alternativa ou Wine

### 2. Verificar Instalação
```bash
# Verificar se o compilador está funcionando
gcc --version

# Verificar se o IDE abre corretamente
# Abrir Dev-C++ e criar um projeto de teste
```

## 🚀 Configuração Inicial

### 1. Primeira Execução
1. Abra o Dev-C++
2. Vá em `Tools > Compiler Options`
3. Configure o compilador GCC
4. Teste com um programa simples

### 2. Configurações Básicas
1. **Editor**: `Tools > Editor Options`
   - Tab size: 4
   - Insert spaces: Yes
   - Auto indent: Yes
   - Show line numbers: Yes

2. **Compilador**: `Tools > Compiler Options`
   - Compiler: GCC
   - Standard: C99
   - Warnings: All
   - Optimization: None (para debug)

3. **Debugger**: `Tools > Debugger Options`
   - Enable debugger: Yes
   - Show debug info: Yes

## ⚙️ Configurações Avançadas

### 1. Configurações do Compilador
```
Tools > Compiler Options > General

Compiler: GCC
Standard: C99
Warnings: All (-Wall -Wextra)
Optimization: None (-O0)
Debug info: Yes (-g)
```

### 2. Configurações do Editor
```
Tools > Editor Options > General

Tab size: 4
Insert spaces: Yes
Auto indent: Yes
Show line numbers: Yes
Show spaces: No
Show tabs: No
Show end of line: No
```

### 3. Configurações do Debugger
```
Tools > Debugger Options > General

Enable debugger: Yes
Show debug info: Yes
Stop at main: Yes
Show call stack: Yes
Show local variables: Yes
```

## 🔧 Uso Básico

### 1. Criar Novo Projeto
1. `File > New > Project`
2. Escolha "Console Application"
3. Selecione "C Project"
4. Digite o nome do projeto
5. Escolha a localização

### 2. Criar Arquivo C
1. `File > New > Source File`
2. Digite seu código
3. `File > Save As` (nome.c)
4. `Project > Add to Project`

### 3. Compilar e Executar
- **Compilar**: `Execute > Compile` (F9)
- **Executar**: `Execute > Run` (F10)
- **Compilar e Executar**: `Execute > Compile & Run` (F11)

### 4. Debug
- **Iniciar Debug**: `Debug > Debug` (F8)
- **Step Over**: `Debug > Step Over` (F8)
- **Step Into**: `Debug > Step Into` (F7)
- **Continue**: `Debug > Continue` (F4)

## 📁 Estrutura de Projeto

### Projeto Simples
```
projeto/
├── projeto.dev          # Arquivo do projeto
├── main.c              # Arquivo principal
├── utils.c             # Arquivo de utilitários
├── utils.h             # Header
├── Makefile            # Makefile gerado
└── bin/                # Arquivos compilados
    └── projeto.exe
```

### Projeto com Múltiplos Arquivos
```
projeto/
├── projeto.dev
├── src/
│   ├── main.c
│   ├── functions.c
│   └── helpers.c
├── include/
│   ├── functions.h
│   └── helpers.h
├── lib/
├── bin/
└── Makefile
```

## 🛠️ Comandos Úteis

### Atalhos de Teclado
- `F9` - Compilar
- `F10` - Executar
- `F11` - Compilar e Executar
- `F8` - Debug
- `F7` - Step Into
- `F4` - Continue
- `Ctrl+S` - Salvar
- `Ctrl+Z` - Desfazer
- `Ctrl+Y` - Refazer
- `Ctrl+F` - Buscar
- `Ctrl+H` - Substituir

### Comandos do Menu
- `File > New > Project` - Novo projeto
- `File > New > Source File` - Novo arquivo
- `Project > Add to Project` - Adicionar arquivo
- `Project > Project Options` - Opções do projeto
- `Tools > Compiler Options` - Opções do compilador
- `Tools > Editor Options` - Opções do editor
- `Tools > Debugger Options` - Opções do debugger

## 🔍 Recursos Avançados

### 1. IntelliSense
- Autocompletar código
- Verificação de erros em tempo real
- Navegação por símbolos
- Refatoração

### 2. Debugging
- Breakpoints condicionais
- Watch variables
- Call stack
- Memory inspection

### 3. Project Management
- Múltiplos arquivos
- Dependências
- Configurações por projeto
- Build configurations

### 4. Code Templates
- Templates pré-definidos
- Templates personalizáveis
- Snippets de código
- Auto-complete

## 🐛 Solução de Problemas

### Problemas Comuns

#### 1. Compilador não encontrado
1. Verificar se GCC está instalado
2. Configurar caminho do compilador
3. Verificar variáveis de ambiente

#### 2. Erros de compilação
1. Verificar sintaxe do código
2. Verificar includes
3. Verificar bibliotecas

#### 3. Debug não funciona
1. Verificar se programa foi compilado com debug
2. Verificar configurações do debugger
3. Verificar se GDB está instalado

#### 4. IDE não abre
1. Verificar permissões
2. Verificar dependências
3. Reinstalar se necessário

### Logs Úteis
```bash
# Verificar versão do GCC
gcc --version

# Verificar se Dev-C++ está no PATH
where devcpp

# Verificar arquivos de configuração
# Geralmente em: C:\Program Files\Dev-Cpp\
```

## 📚 Recursos Adicionais

### Documentação
- [Dev-C++ Documentation](https://sourceforge.net/projects/orwelldevcpp/)
- [GCC Manual](https://gcc.gnu.org/onlinedocs/)
- [C Programming Tutorial](https://www.tutorialspoint.com/cprogramming/)

### Comunidade
- [Dev-C++ Forum](https://sourceforge.net/projects/orwelldevcpp/forums/)
- [Stack Overflow](https://stackoverflow.com/questions/tagged/dev-c++)
- [Reddit r/devcpp](https://www.reddit.com/r/devcpp/)

### Plugins Úteis
- **Code Formatter**: Formatação automática
- **Syntax Highlighter**: Destaque de sintaxe
- **Auto Complete**: Autocompletar avançado
- **Project Manager**: Gerenciamento de projetos

## 🎯 Dicas de Produtividade

### 1. Templates
Crie templates personalizados para código repetitivo:
```c
// Template para função main
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    // Seu código aqui
    return 0;
}
```

### 2. Snippets
Use snippets para código comum:
```c
// Snippet para função
void function_name() {
    // Implementação
}
```

### 3. Debugging
- Use breakpoints estratégicos
- Monitore variáveis importantes
- Use o call stack para entender o fluxo

### 4. Organização
- Mantenha arquivos organizados
- Use nomes descritivos
- Documente seu código
- Use comentários adequados

## 🚀 Próximos Passos

1. **Explore recursos**: Teste diferentes funcionalidades
2. **Configure debug**: Aprenda a usar o debugger eficientemente
3. **Crie templates**: Desenvolva templates personalizados
4. **Organize projetos**: Aprenda a gerenciar projetos complexos
5. **Integre ferramentas**: Use ferramentas externas quando necessário

## 📝 Configurações Recomendadas

### Para Iniciantes
```
Compiler Options:
- Standard: C99
- Warnings: All
- Optimization: None
- Debug info: Yes

Editor Options:
- Tab size: 4
- Insert spaces: Yes
- Show line numbers: Yes
- Auto indent: Yes
```

### Para Desenvolvimento
```
Compiler Options:
- Standard: C99
- Warnings: All
- Optimization: Level 2
- Debug info: Yes

Editor Options:
- Tab size: 4
- Insert spaces: Yes
- Show line numbers: Yes
- Auto indent: Yes
- Show spaces: Yes
- Show tabs: Yes
```

---

*Configuração otimizada para desenvolvimento em C com Dev-C++* 