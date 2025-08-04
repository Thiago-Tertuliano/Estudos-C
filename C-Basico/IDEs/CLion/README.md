# CLion para Desenvolvimento em C

## 🎯 Visão Geral

O CLion é um IDE profissional da JetBrains para desenvolvimento em C/C++. É pago, mas oferece recursos avançados como refatoração inteligente, análise de código e debugging poderoso.

## 📋 Pré-requisitos

### 1. Instalar CLion
- **Todas as plataformas**: Baixar do [site oficial](https://www.jetbrains.com/clion/)
- **Licença**: Pago (há versão gratuita para estudantes)
- **Trial**: 30 dias gratuitos

### 2. Verificar Instalação
```bash
# Verificar se o compilador está funcionando
gcc --version

# Verificar se CLion abre corretamente
# Abrir CLion e criar um projeto de teste
```

## 🚀 Configuração Inicial

### 1. Primeira Execução
1. Abra o CLion
2. Vá em `File > New Project`
3. Escolha "C Executable"
4. Configure o compilador
5. Teste com um programa simples

### 2. Configurações Básicas
1. **Editor**: `Settings > Editor`
   - Tab size: 4
   - Insert spaces: Yes
   - Auto indent: Yes
   - Show line numbers: Yes

2. **Compilador**: `Settings > Build, Execution, Deployment > Toolchains`
   - Compiler: GCC
   - Standard: C99
   - Warnings: All
   - Optimization: None (para debug)

3. **Debugger**: `Settings > Build, Execution, Deployment > Debugger`
   - Enable debugger: Yes
   - Show debug info: Yes

## ⚙️ Configurações Avançadas

### 1. Configurações do Compilador
```
Settings > Build, Execution, Deployment > Toolchains

Compiler: GCC
Standard: C99
Warnings: All (-Wall -Wextra)
Optimization: None (-O0)
Debug info: Yes (-g)
```

### 2. Configurações do Editor
```
Settings > Editor > General

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
Settings > Build, Execution, Deployment > Debugger

Enable debugger: Yes
Show debug info: Yes
Stop at main: Yes
Show call stack: Yes
Show local variables: Yes
```

## 🔧 Uso Básico

### 1. Criar Novo Projeto
1. `File > New Project`
2. Escolha "C Executable"
3. Digite o nome do projeto
4. Escolha a localização
5. Configure o compilador

### 2. Criar Arquivo C
1. `File > New > C/C++ Single File`
2. Digite seu código
3. `File > Save As` (nome.c)
4. Adicione ao projeto

### 3. Compilar e Executar
- **Compilar**: `Build > Build Project` (Ctrl+F9)
- **Executar**: `Run > Run` (Shift+F10)
- **Compilar e Executar**: `Run > Run` (Shift+F10)

### 4. Debug
- **Iniciar Debug**: `Run > Debug` (Shift+F9)
- **Step Over**: `Debug > Step Over` (F8)
- **Step Into**: `Debug > Step Into` (F7)
- **Continue**: `Debug > Resume Program` (F9)

## 📁 Estrutura de Projeto

### Projeto Simples
```
projeto/
├── CMakeLists.txt       # Arquivo CMake
├── main.c              # Arquivo principal
├── utils.c             # Arquivo de utilitários
├── utils.h             # Header
├── cmake-build-debug/  # Arquivos de build
└── .idea/              # Configurações do CLion
```

### Projeto com Múltiplos Arquivos
```
projeto/
├── CMakeLists.txt
├── src/
│   ├── main.c
│   ├── functions.c
│   └── helpers.c
├── include/
│   ├── functions.h
│   └── helpers.h
├── lib/
├── cmake-build-debug/
└── .idea/
```

## 🛠️ Comandos Úteis

### Atalhos de Teclado
- `Ctrl+F9` - Build Project
- `Shift+F10` - Run
- `Shift+F9` - Debug
- `F8` - Step Over
- `F7` - Step Into
- `F9` - Resume Program
- `Ctrl+S` - Salvar
- `Ctrl+Z` - Desfazer
- `Ctrl+Y` - Refazer
- `Ctrl+F` - Buscar
- `Ctrl+H` - Substituir

### Comandos do Menu
- `File > New > Project` - Novo projeto
- `File > New > C/C++ Single File` - Novo arquivo
- `Project > Add files` - Adicionar arquivo
- `File > Settings` - Configurações
- `Build > Build Project` - Compilar projeto
- `Run > Run` - Executar
- `Run > Debug` - Debug

## 🔍 Recursos Avançados

### 1. IntelliSense
- Autocompletar código avançado
- Verificação de erros em tempo real
- Navegação por símbolos
- Refatoração inteligente

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
- CMake integration

### 4. Code Analysis
- Static analysis
- Code inspection
- Performance analysis
- Memory leak detection

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

# Verificar se CLion está no PATH
which clion

# Verificar arquivos de configuração
# Geralmente em: ~/.CLion/
```

## 📚 Recursos Adicionais

### Documentação
- [CLion Documentation](https://www.jetbrains.com/help/clion/)
- [GCC Manual](https://gcc.gnu.org/onlinedocs/)
- [C Programming Tutorial](https://www.tutorialspoint.com/cprogramming/)

### Comunidade
- [CLion Forum](https://intellij-support.jetbrains.com/hc/en-us/community/topics/200366979-IntelliJ-IDEA-IntelliJ-IDEA)
- [Stack Overflow](https://stackoverflow.com/questions/tagged/clion)
- [Reddit r/clion](https://www.reddit.com/r/clion/)

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

*Configuração otimizada para desenvolvimento em C com CLion* 