# Visual Studio Code para Desenvolvimento em C

## 🎯 Visão Geral

O Visual Studio Code é um editor de código moderno, gratuito e altamente extensível da Microsoft. É ideal para desenvolvimento em C devido à sua simplicidade, velocidade e excelente suporte através de extensões.

## 📋 Pré-requisitos

### 1. Instalar VSCode
- **Windows**: Baixar do [site oficial](https://code.visualstudio.com/)
- **macOS**: Baixar do site ou usar Homebrew: `brew install --cask visual-studio-code`
- **Linux**: Baixar do site ou usar package manager

### 2. Instalar Compilador
```bash
# Ubuntu/Debian
sudo apt update
sudo apt install build-essential

# CentOS/RHEL
sudo yum groupinstall "Development Tools"

# macOS
xcode-select --install

# Windows
# Instalar MinGW ou usar WSL
```

### 3. Verificar Instalação
```bash
# Verificar GCC
gcc --version

# Verificar Make
make --version

# Verificar GDB (debugger)
gdb --version
```

## 🚀 Configuração Inicial

### 1. Abrir VSCode
```bash
# Abrir VSCode no terminal
code .

# Ou abrir uma pasta específica
code /caminho/para/seu/projeto
```

### 2. Instalar Extensões Essenciais
Abra o VSCode e vá em `Ctrl+Shift+X` (ou `Cmd+Shift+X` no macOS) e instale:

#### Extensões Principais
- **C/C++** (Microsoft) - Suporte principal para C/C++
- **C/C++ Extension Pack** - Pacote completo
- **Code Runner** - Executar código rapidamente
- **C/C++ Themes** - Temas para C/C++

#### Extensões Recomendadas
- **GitLens** - Integração Git avançada
- **Bracket Pair Colorizer** - Colorir parênteses
- **Auto Rename Tag** - Renomear automaticamente
- **Path Intellisense** - Autocompletar caminhos
- **Material Icon Theme** - Ícones bonitos

### 3. Configurar Workspace
1. Abra a pasta do seu projeto
2. Vá em `File > Save Workspace As...`
3. Salve como `workspace.code-workspace`

## ⚙️ Configurações

### 1. Settings.json
Copie as configurações do arquivo `settings.json` para seu workspace:

```json
{
    "C_Cpp.default.cStandard": "c99",
    "C_Cpp.default.cppStandard": "c++17",
    "C_Cpp.default.compilerPath": "/usr/bin/gcc",
    "C_Cpp.default.intelliSenseMode": "gcc-x64",
    "C_Cpp.default.includePath": [
        "${workspaceFolder}/**",
        "/usr/include",
        "/usr/local/include"
    ],
    "C_Cpp.default.defines": [],
    "C_Cpp.default.warningLevel": "Warning",
    "C_Cpp.default.cStandard": "c99",
    "C_Cpp.default.cppStandard": "c++17",
    "C_Cpp.default.compilerPath": "/usr/bin/gcc",
    "C_Cpp.default.intelliSenseMode": "gcc-x64",
    "C_Cpp.default.includePath": [
        "${workspaceFolder}/**",
        "/usr/include",
        "/usr/local/include"
    ],
    "C_Cpp.default.defines": [],
    "C_Cpp.default.warningLevel": "Warning",
    "files.associations": {
        "*.c": "c",
        "*.h": "c",
        "*.cpp": "cpp",
        "*.hpp": "cpp"
    },
    "editor.formatOnSave": true,
    "editor.formatOnType": true,
    "editor.tabSize": 4,
    "editor.insertSpaces": true,
    "editor.detectIndentation": true,
    "files.trimTrailingWhitespace": true,
    "files.insertFinalNewline": true,
    "files.trimFinalNewlines": true
}
```

### 2. Tasks.json
Configure tarefas de compilação no arquivo `tasks.json`:

```json
{
    "version": "2.0.0",
    "tasks": [
        {
            "label": "build",
            "type": "shell",
            "command": "gcc",
            "args": [
                "-g",
                "-Wall",
                "-Wextra",
                "-std=c99",
                "${file}",
                "-o",
                "${fileBasenameNoExtension}"
            ],
            "group": {
                "kind": "build",
                "isDefault": true
            },
            "presentation": {
                "echo": true,
                "reveal": "always",
                "focus": false,
                "panel": "shared"
            },
            "problemMatcher": ["$gcc"]
        },
        {
            "label": "build with make",
            "type": "shell",
            "command": "make",
            "group": "build",
            "presentation": {
                "echo": true,
                "reveal": "always",
                "focus": false,
                "panel": "shared"
            },
            "problemMatcher": ["$gcc"]
        }
    ]
}
```

### 3. Launch.json
Configure debug no arquivo `launch.json`:

```json
{
    "version": "0.2.0",
    "configurations": [
        {
            "name": "Debug",
            "type": "cppdbg",
            "request": "launch",
            "program": "${fileDirname}/${fileBasenameNoExtension}",
            "args": [],
            "stopAtEntry": false,
            "cwd": "${fileDirname}",
            "environment": [],
            "externalConsole": false,
            "MIMode": "gdb",
            "setupCommands": [
                {
                    "description": "Enable pretty-printing for gdb",
                    "text": "-enable-pretty-printing",
                    "ignoreFailures": true
                }
            ],
            "preLaunchTask": "build"
        }
    ]
}
```

## 🔧 Uso Básico

### 1. Criar Arquivo C
1. Abra VSCode
2. Crie um novo arquivo (`Ctrl+N`)
3. Salve como `programa.c`
4. Digite seu código

### 2. Compilar e Executar
```bash
# Método 1: Usando Code Runner
# Clique no ícone ▶️ no canto superior direito

# Método 2: Usando Terminal
gcc -Wall -Wextra -std=c99 -g programa.c -o programa
./programa

# Método 3: Usando Tasks
Ctrl+Shift+P > Tasks: Run Task > build
```

### 3. Debug
1. Coloque breakpoints clicando na margem esquerda
2. Pressione `F5` para iniciar debug
3. Use `F10` para step over, `F11` para step into

## 📁 Estrutura de Projeto

### Projeto Simples
```
projeto/
├── src/
│   ├── main.c
│   └── utils.c
├── include/
│   └── utils.h
├── build/
├── .vscode/
│   ├── settings.json
│   ├── tasks.json
│   └── launch.json
└── Makefile
```

### Projeto com Múltiplos Arquivos
```
projeto/
├── src/
│   ├── main.c
│   ├── functions.c
│   └── helpers.c
├── include/
│   ├── functions.h
│   └── helpers.h
├── lib/
├── build/
├── tests/
├── docs/
├── .vscode/
└── Makefile
```

## 🛠️ Comandos Úteis

### Atalhos de Teclado
- `Ctrl+Shift+P` - Paleta de comandos
- `Ctrl+Space` - Autocompletar
- `F12` - Ir para definição
- `Shift+F12` - Encontrar todas as referências
- `Ctrl+K Ctrl+F` - Formatar código
- `Ctrl+/` - Comentar/descomentar
- `Alt+Shift+F` - Formatar documento

### Comandos do Terminal
```bash
# Compilar arquivo único
gcc -Wall -Wextra -std=c99 -g arquivo.c -o arquivo

# Compilar múltiplos arquivos
gcc -Wall -Wextra -std=c99 -g *.c -o programa

# Compilar com bibliotecas
gcc -Wall -Wextra -std=c99 -g main.c -lm -o programa

# Debug com GDB
gcc -g arquivo.c -o arquivo
gdb arquivo
```

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

### 3. Git Integration
- Controle de versão integrado
- Diff viewer
- Branch management
- Commit history

### 4. Extensions
- **C/C++ Themes**: Temas específicos para C
- **Bracket Pair Colorizer**: Colorir parênteses
- **Auto Rename Tag**: Renomear automaticamente
- **Path Intellisense**: Autocompletar caminhos

## 🐛 Solução de Problemas

### Problemas Comuns

#### 1. GCC não encontrado
```bash
# Verificar se GCC está no PATH
which gcc

# Adicionar ao PATH se necessário
export PATH=$PATH:/usr/bin
```

#### 2. IntelliSense não funciona
1. Verificar se a extensão C/C++ está instalada
2. Recarregar VSCode (`Ctrl+Shift+P` > "Developer: Reload Window")
3. Verificar configurações do `c_cpp_properties.json`

#### 3. Debug não funciona
1. Verificar se GDB está instalado
2. Verificar configurações do `launch.json`
3. Verificar se o programa foi compilado com `-g`

#### 4. Tasks não funcionam
1. Verificar se `tasks.json` está na pasta `.vscode`
2. Verificar se o comando GCC está correto
3. Verificar se o arquivo está salvo

### Logs Úteis
```bash
# Verificar versão do VSCode
code --version

# Verificar extensões instaladas
code --list-extensions

# Abrir VSCode em modo verbose
code --verbose
```

## 📚 Recursos Adicionais

### Documentação
- [VSCode Documentation](https://code.visualstudio.com/docs)
- [C/C++ Extension](https://marketplace.visualstudio.com/items?itemName=ms-vscode.cpptools)
- [GCC Manual](https://gcc.gnu.org/onlinedocs/)

### Comunidade
- [VSCode GitHub](https://github.com/microsoft/vscode)
- [Stack Overflow](https://stackoverflow.com/questions/tagged/visual-studio-code)
- [Reddit r/vscode](https://www.reddit.com/r/vscode/)

### Plugins Úteis
- **GitLens**: Git integration avançada
- **Live Share**: Colaboração em tempo real
- **Thunder Client**: Testar APIs
- **Markdown All in One**: Suporte Markdown

## 🎯 Dicas de Produtividade

### 1. Snippets
Crie snippets personalizados para código repetitivo:
```json
{
    "C main function": {
        "prefix": "main",
        "body": [
            "#include <stdio.h>",
            "#include <stdlib.h>",
            "",
            "int main() {",
            "    $1",
            "    return 0;",
            "}"
        ],
        "description": "C main function"
    }
}
```

### 2. Multi-cursor
- `Ctrl+Click` - Adicionar cursor
- `Alt+Click` - Adicionar cursor
- `Ctrl+Alt+↑/↓` - Adicionar cursor acima/abaixo

### 3. Terminal Integrado
- `Ctrl+`` - Abrir/fechar terminal
- `Ctrl+Shift+`` - Novo terminal
- `Ctrl+Shift+5` - Dividir terminal

### 4. Workspace
- Salve configurações específicas do projeto
- Use diferentes workspaces para diferentes projetos
- Configure tasks específicas por projeto

## 🚀 Próximos Passos

1. **Explore extensões**: Teste diferentes extensões para C
2. **Configure debug**: Aprenda a usar o debugger eficientemente
3. **Automatize**: Crie tasks e scripts personalizados
4. **Colabore**: Use Live Share para trabalhar em equipe
5. **Versionamento**: Integre com Git para controle de versão

---

*Configuração otimizada para desenvolvimento em C com VSCode* 