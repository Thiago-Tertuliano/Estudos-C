# Eclipse CDT para Desenvolvimento em C

## 🎯 Visão Geral

O Eclipse CDT (C/C++ Development Tools) é um IDE gratuito e muito extensível para desenvolvimento em C/C++. É ideal para projetos grandes e desenvolvimento em equipe.

## 📋 Pré-requisitos

### 1. Instalar Eclipse CDT
- **Todas as plataformas**: Baixar do [site oficial](https://www.eclipse.org/cdt/)
- **Gratuito**: Totalmente gratuito
- **Java**: Requer JRE/JDK instalado

### 2. Verificar Instalação
```bash
# Verificar se Java está instalado
java --version

# Verificar se o compilador está funcionando
gcc --version

# Verificar se Eclipse abre corretamente
# Abrir Eclipse e criar um projeto de teste
```

## 🚀 Configuração Inicial

### 1. Primeira Execução
1. Abra o Eclipse
2. Escolha um workspace
3. Vá em `File > New > C Project`
4. Configure o compilador GCC
5. Teste com um programa simples

### 2. Configurações Básicas
1. **Editor**: `Window > Preferences > C/C++ > Editor`
   - Tab size: 4
   - Insert spaces: Yes
   - Auto indent: Yes
   - Show line numbers: Yes

2. **Compilador**: `Window > Preferences > C/C++ > Build > Settings`
   - Compiler: GCC
   - Standard: C99
   - Warnings: All
   - Optimization: None (para debug)

3. **Debugger**: `Window > Preferences > C/C++ > Debug`
   - Enable debugger: Yes
   - Show debug info: Yes

## ⚙️ Configurações Avançadas

### 1. Configurações do Compilador
```
Window > Preferences > C/C++ > Build > Settings

Compiler: GCC
Standard: C99
Warnings: All (-Wall -Wextra)
Optimization: None (-O0)
Debug info: Yes (-g)
```

### 2. Configurações do Editor
```
Window > Preferences > C/C++ > Editor > General

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
Window > Preferences > C/C++ > Debug

Enable debugger: Yes
Show debug info: Yes
Stop at main: Yes
Show call stack: Yes
Show local variables: Yes
```

## 🔧 Uso Básico

### 1. Criar Novo Projeto
1. `File > New > C Project`
2. Escolha "Executable"
3. Selecione "Empty Project"
4. Digite o nome do projeto
5. Escolha a localização

### 2. Criar Arquivo C
1. `File > New > Source File`
2. Digite seu código
3. `File > Save` (nome.c)
4. Adicione ao projeto

### 3. Compilar e Executar
- **Compilar**: `Project > Build Project` (Ctrl+B)
- **Executar**: `Run > Run` (Ctrl+F11)
- **Compilar e Executar**: `Run > Run` (Ctrl+F11)

### 4. Debug
- **Iniciar Debug**: `Run > Debug` (F11)
- **Step Over**: `Run > Step Over` (F6)
- **Step Into**: `Run > Step Into` (F5)
- **Continue**: `Run > Resume` (F8)

## 📁 Estrutura de Projeto

### Projeto Simples
```
projeto/
├── .project             # Arquivo do projeto
├── .cproject           # Configuração C/C++
├── main.c              # Arquivo principal
├── utils.c             # Arquivo de utilitários
├── utils.h             # Header
├── Debug/              # Arquivos de build
└── Release/            # Arquivos de release
```

### Projeto com Múltiplos Arquivos
```
projeto/
├── .project
├── .cproject
├── src/
│   ├── main.c
│   ├── functions.c
│   └── helpers.c
├── include/
│   ├── functions.h
│   └── helpers.h
├── lib/
├── Debug/
└── Release/
```

## 🛠️ Comandos Úteis

### Atalhos de Teclado
- `Ctrl+B` - Build Project
- `Ctrl+F11` - Run
- `F11` - Debug
- `F6` - Step Over
- `F5` - Step Into
- `F8` - Resume
- `Ctrl+S` - Salvar
- `Ctrl+Z` - Desfazer
- `Ctrl+Y` - Refazer
- `Ctrl+F` - Buscar
- `Ctrl+H` - Substituir

### Comandos do Menu
- `File > New > C Project` - Novo projeto
- `File > New > Source File` - Novo arquivo
- `Project > Add files` - Adicionar arquivo
- `Project > Properties` - Propriedades do projeto
- `Window > Preferences` - Configurações
- `Project > Build Project` - Compilar projeto
- `Run > Run` - Executar
- `Run > Debug` - Debug

## 🔍 Recursos Avançados

### 1. IntelliSense
- Autocompletar código avançado
- Verificação de erros em tempo real
- Navegação por símbolos
- Refatoração

### 2. Debugging
- Breakpoints condicionais
- Watch variables
- Call stack
- Memory inspection
- Expression evaluation

### 3. Project Management
- Múltiplos arquivos
- Dependências
- Configurações por projeto
- Build configurations
- Makefile generation

### 4. Plugins
- Code formatter
- Syntax highlighter
- Auto complete
- Project manager
- Git integration

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
1. Verificar se Java está instalado
2. Verificar permissões
3. Verificar dependências

### Logs Úteis
```bash
# Verificar versão do Java
java --version

# Verificar versão do GCC
gcc --version

# Verificar se Eclipse está no PATH
which eclipse

# Verificar arquivos de configuração
# Geralmente em: ~/.eclipse/
```

## 📚 Recursos Adicionais

### Documentação
- [Eclipse CDT Documentation](https://www.eclipse.org/cdt/documentation.php)
- [GCC Manual](https://gcc.gnu.org/onlinedocs/)
- [C Programming Tutorial](https://www.tutorialspoint.com/cprogramming/)

### Comunidade
- [Eclipse CDT Forum](https://www.eclipse.org/forums/)
- [Stack Overflow](https://stackoverflow.com/questions/tagged/eclipse-cdt)
- [Reddit r/eclipse](https://www.reddit.com/r/eclipse/)

### Plugins Úteis
- **Code Formatter**: Formatação automática
- **Syntax Highlighter**: Destaque de sintaxe
- **Auto Complete**: Autocompletar avançado
- **Project Manager**: Gerenciamento de projetos
- **Git Integration**: Controle de versão

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
Compiler Settings:
- Standard: C99
- Warnings: All
- Optimization: None
- Debug info: Yes

Editor Settings:
- Tab size: 4
- Insert spaces: Yes
- Show line numbers: Yes
- Auto indent: Yes
```

### Para Desenvolvimento
```
Compiler Settings:
- Standard: C99
- Warnings: All
- Optimization: Level 2
- Debug info: Yes

Editor Settings:
- Tab size: 4
- Insert spaces: Yes
- Show line numbers: Yes
- Auto indent: Yes
- Show spaces: Yes
- Show tabs: Yes
```

---

*Configuração otimizada para desenvolvimento em C com Eclipse CDT* 