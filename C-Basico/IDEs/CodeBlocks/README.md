# Code::Blocks para Desenvolvimento em C

## 🎯 Visão Geral

O Code::Blocks é um IDE gratuito, multiplataforma e robusto para desenvolvimento em C/C++. É ideal para desenvolvimento profissional devido aos seus recursos avançados e estabilidade.

## 📋 Pré-requisitos

### 1. Instalar Code::Blocks
- **Windows**: Baixar do [site oficial](http://www.codeblocks.org/)
- **Linux**: `sudo apt install codeblocks` (Ubuntu/Debian)
- **macOS**: Baixar do site ou usar Homebrew

### 2. Verificar Instalação
```bash
# Verificar se Code::Blocks está instalado
codeblocks --version

# Verificar se o compilador está funcionando
gcc --version
```

## 🚀 Configuração Inicial

### 1. Primeira Execução
1. Abra o Code::Blocks
2. Vá em `Settings > Compiler`
3. Configure o compilador GCC
4. Teste com um projeto simples

### 2. Configurações Básicas
1. **Editor**: `Settings > Editor`
   - Tab size: 4
   - Insert spaces: Yes
   - Auto indent: Yes
   - Show line numbers: Yes

2. **Compilador**: `Settings > Compiler`
   - Compiler: GCC
   - Standard: C99
   - Warnings: All
   - Optimization: None (para debug)

3. **Debugger**: `Settings > Debugger`
   - Enable debugger: Yes
   - Show debug info: Yes

## ⚙️ Configurações Avançadas

### 1. Configurações do Compilador
```
Settings > Compiler > Global compiler settings

Compiler: GCC
Standard: C99
Warnings: All (-Wall -Wextra)
Optimization: None (-O0)
Debug info: Yes (-g)
```

### 2. Configurações do Editor
```
Settings > Editor > General settings

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
Settings > Debugger > GDB/CDB debugger

Enable debugger: Yes
Show debug info: Yes
Stop at main: Yes
Show call stack: Yes
Show local variables: Yes
```

## 🔧 Uso Básico

### 1. Criar Novo Projeto
1. `File > New > Project`
2. Escolha "Console application"
3. Selecione "C"
4. Digite o nome do projeto
5. Escolha a localização

### 2. Criar Arquivo C
1. `File > New > Empty file`
2. Digite seu código
3. `File > Save As` (nome.c)
4. `Project > Add files`

### 3. Compilar e Executar
- **Compilar**: `Build > Build` (F9)
- **Executar**: `Build > Run` (F10)
- **Compilar e Executar**: `Build > Build and run` (F11)

### 4. Debug
- **Iniciar Debug**: `Debug > Start` (F8)
- **Step Over**: `Debug > Step over` (F8)
- **Step Into**: `Debug > Step into` (F7)
- **Continue**: `Debug > Continue` (F5)

## 📁 Estrutura de Projeto

### Projeto Simples
```
projeto/
├── projeto.cbp          # Arquivo do projeto
├── main.c              # Arquivo principal
├── utils.c             # Arquivo de utilitários
├── utils.h             # Header
├── Makefile            # Makefile gerado
└── bin/                # Arquivos compilados
    └── projeto
```

### Projeto com Múltiplos Arquivos
```
projeto/
├── projeto.cbp
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
- `F9` - Build
- `F10` - Run
- `F11` - Build and run
- `F8` - Debug
- `F7` - Step into
- `F5` - Continue
- `Ctrl+S` - Salvar
- `Ctrl+Z` - Desfazer
- `Ctrl+Y` - Refazer
- `Ctrl+F` - Buscar
- `Ctrl+H` - Substituir

### Comandos do Menu
- `File > New > Project` - Novo projeto
- `File > New > Empty file` - Novo arquivo
- `Project > Add files` - Adicionar arquivo
- `Project > Project options` - Opções do projeto
- `Settings > Compiler` - Opções do compilador
- `Settings > Editor` - Opções do editor
- `Settings > Debugger` - Opções do debugger

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

### 4. Plugins
- Code formatter
- Syntax highlighter
- Auto complete
- Project manager

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

# Verificar se Code::Blocks está no PATH
which codeblocks

# Verificar arquivos de configuração
# Geralmente em: ~/.codeblocks/
```

## 📚 Recursos Adicionais

### Documentação
- [Code::Blocks Documentation](http://www.codeblocks.org/)
- [GCC Manual](https://gcc.gnu.org/onlinedocs/)
- [C Programming Tutorial](https://www.tutorialspoint.com/cprogramming/)

### Comunidade
- [Code::Blocks Forum](http://forums.codeblocks.org/)
- [Stack Overflow](https://stackoverflow.com/questions/tagged/codeblocks)
- [Reddit r/codeblocks](https://www.reddit.com/r/codeblocks/)

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

*Configuração otimizada para desenvolvimento em C com Code::Blocks* 