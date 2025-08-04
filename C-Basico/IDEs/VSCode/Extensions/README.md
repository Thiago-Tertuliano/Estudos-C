# Extensões do VSCode para Desenvolvimento em C

## 🎯 Extensões Essenciais

### 1. C/C++ (Microsoft)
- **ID**: `ms-vscode.cpptools`
- **Descrição**: Suporte principal para C/C++
- **Recursos**:
  - IntelliSense avançado
  - Debugging integrado
  - Navegação por símbolos
  - Refatoração
  - Formatação de código

### 2. C/C++ Extension Pack
- **ID**: `ms-vscode.cpptools-extension-pack`
- **Descrição**: Pacote completo para C/C++
- **Inclui**:
  - C/C++
  - C/C++ Themes
  - CMake Tools
  - CMake

### 3. Code Runner
- **ID**: `formulahendry.code-runner`
- **Descrição**: Executar código rapidamente
- **Recursos**:
  - Executar arquivo atual
  - Executar seleção
  - Suporte a múltiplas linguagens

### 4. C/C++ Themes
- **ID**: `ms-vscode.cpptools-themes`
- **Descrição**: Temas específicos para C/C++
- **Temas incluídos**:
  - Dark+
  - Light+
  - High Contrast

## 🔧 Extensões Recomendadas

### 5. GitLens
- **ID**: `eamodio.gitlens`
- **Descrição**: Git integration avançada
- **Recursos**:
  - Histórico de linhas
  - Comparação de branches
  - Blame annotations
  - File history

### 6. Bracket Pair Colorizer
- **ID**: `CoenraadS.bracket-pair-colorizer-2`
- **Descrição**: Colorir parênteses e chaves
- **Recursos**:
  - Colorização automática
  - Configuração personalizada
  - Suporte a múltiplas linguagens

### 7. Auto Rename Tag
- **ID**: `formulahendry.auto-rename-tag`
- **Descrição**: Renomear tags automaticamente
- **Recursos**:
  - Renomear pares de tags
  - Suporte a HTML/XML
  - Configuração personalizada

### 8. Path Intellisense
- **ID**: `christian-kohler.path-intellisense`
- **Descrição**: Autocompletar caminhos
- **Recursos**:
  - Autocompletar arquivos
  - Autocompletar pastas
  - Configuração personalizada

### 9. Material Icon Theme
- **ID**: `PKief.material-icon-theme`
- **Descrição**: Ícones bonitos para arquivos
- **Recursos**:
  - Ícones para C/C++
  - Ícones para diferentes tipos de arquivo
  - Configuração personalizada

## 🛠️ Extensões Avançadas

### 10. clang-format
- **ID**: `xaver.clang-format`
- **Descrição**: Formatação de código C/C++
- **Recursos**:
  - Formatação automática
  - Configuração personalizada
  - Integração com VSCode

### 11. C/C++ Compile Run
- **ID**: `danielpinto8zz6.c-cpp-compile-run`
- **Descrição**: Compilar e executar rapidamente
- **Recursos**:
  - Compilação rápida
  - Execução automática
  - Configuração personalizada

### 12. C/C++ Snippets
- **ID**: `hars.CppSnippets`
- **Descrição**: Snippets para C/C++
- **Recursos**:
  - Snippets pré-definidos
  - Snippets personalizáveis
  - Suporte a múltiplos padrões

### 13. Include Autocomplete
- **ID**: `steve8708.include-autocomplete`
- **Descrição**: Autocompletar includes
- **Recursos**:
  - Autocompletar headers
  - Busca inteligente
  - Configuração personalizada

### 14. C/C++ Advanced Lint
- **ID**: `jbenden.c-cpp-flylint`
- **Descrição**: Linting avançado para C/C++
- **Recursos**:
  - Múltiplos linters
  - Configuração personalizada
  - Integração com VSCode

## 📊 Extensões de Produtividade

### 15. Live Share
- **ID**: `MS-vsliveshare.vsliveshare`
- **Descrição**: Colaboração em tempo real
- **Recursos**:
  - Edição colaborativa
  - Debugging compartilhado
  - Terminal compartilhado

### 16. Thunder Client
- **ID**: `rangav.vscode-thunder-client`
- **Descrição**: Cliente HTTP integrado
- **Recursos**:
  - Testar APIs
  - Requisições HTTP
  - Configuração personalizada

### 17. Markdown All in One
- **ID**: `yzhang.markdown-all-in-one`
- **Descrição**: Suporte completo para Markdown
- **Recursos**:
  - Preview de Markdown
  - Formatação automática
  - Lista de tarefas

### 18. Todo Tree
- **ID**: `Gruntfuggly.todo-tree`
- **Descrição**: Gerenciar TODOs no código
- **Recursos**:
  - Lista de TODOs
  - Filtros personalizados
  - Configuração personalizada

## 🎨 Extensões de Tema

### 19. One Dark Pro
- **ID**: `zhuangtongfa.Material-theme`
- **Descrição**: Tema baseado no Atom
- **Recursos**:
  - Cores suaves
  - Alto contraste
  - Configuração personalizada

### 20. Dracula Official
- **ID**: `dracula-theme.theme-dracula`
- **Descrição**: Tema Dracula
- **Recursos**:
  - Cores vibrantes
  - Alto contraste
  - Configuração personalizada

### 21. Monokai Pro
- **ID**: `monokai.theme-monokai-pro-vscode`
- **Descrição**: Tema Monokai Pro
- **Recursos**:
  - Cores vibrantes
  - Alto contraste
  - Configuração personalizada

## 🔍 Extensões de Debug

### 22. Debug Visualizer
- **ID**: `hediet.debug-visualizer`
- **Descrição**: Visualização de dados durante debug
- **Recursos**:
  - Visualização de arrays
  - Visualização de estruturas
  - Configuração personalizada

### 23. Error Lens
- **ID**: `usernamehw.errorlens`
- **Descrição**: Mostrar erros inline
- **Recursos**:
  - Erros inline
  - Warnings inline
  - Configuração personalizada

## 📝 Como Instalar

### Método 1: Interface Gráfica
1. Abra VSCode
2. Pressione `Ctrl+Shift+X`
3. Pesquise o nome da extensão
4. Clique em "Install"

### Método 2: Linha de Comando
```bash
# Instalar extensão específica
code --install-extension ms-vscode.cpptools

# Instalar múltiplas extensões
code --install-extension ms-vscode.cpptools
code --install-extension formulahendry.code-runner
code --install-extension PKief.material-icon-theme
```

### Método 3: Arquivo de Configuração
Crie um arquivo `extensions.json` no workspace:

```json
{
    "recommendations": [
        "ms-vscode.cpptools",
        "formulahendry.code-runner",
        "PKief.material-icon-theme",
        "eamodio.gitlens",
        "CoenraadS.bracket-pair-colorizer-2",
        "christian-kohler.path-intellisense",
        "danielpinto8zz6.c-cpp-compile-run",
        "hars.CppSnippets",
        "steve8708.include-autocomplete",
        "jbenden.c-cpp-flylint"
    ]
}
```

## ⚙️ Configurações Recomendadas

### Para C/C++ Extension
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
    "C_Cpp.default.warningLevel": "Warning"
}
```

### Para Code Runner
```json
{
    "code-runner.executorMap": {
        "c": "cd $dir && gcc -Wall -Wextra -std=c99 $fileName -o $fileNameWithoutExt && $dir$fileNameWithoutExt"
    },
    "code-runner.runInTerminal": true,
    "code-runner.saveFileBeforeRun": true
}
```

### Para Bracket Pair Colorizer
```json
{
    "bracket-pair-colorizer-2.colors": [
        "#ff0000",
        "#00ff00",
        "#0000ff",
        "#ffff00",
        "#ff00ff",
        "#00ffff"
    ],
    "bracket-pair-colorizer-2.showBracketsInGutter": true,
    "bracket-pair-colorizer-2.showBracketsInRuler": true
}
```

## 🚀 Dicas de Uso

### 1. Atalhos Úteis
- `Ctrl+Shift+X` - Abrir extensões
- `Ctrl+Shift+P` - Paleta de comandos
- `F1` - Paleta de comandos
- `Ctrl+Space` - Autocompletar

### 2. Comandos Úteis
```bash
# Listar extensões instaladas
code --list-extensions

# Desinstalar extensão
code --uninstall-extension ms-vscode.cpptools

# Atualizar extensões
code --update-extensions
```

### 3. Configurações Personalizadas
- Crie um arquivo `settings.json` no workspace
- Configure extensões específicas do projeto
- Use diferentes configurações para diferentes projetos

## 🐛 Solução de Problemas

### Problemas Comuns

#### 1. IntelliSense não funciona
1. Verificar se a extensão C/C++ está instalada
2. Recarregar VSCode
3. Verificar configurações do `c_cpp_properties.json`

#### 2. Code Runner não funciona
1. Verificar se a extensão está instalada
2. Verificar configurações do `settings.json`
3. Verificar se o compilador está no PATH

#### 3. Debug não funciona
1. Verificar se GDB está instalado
2. Verificar configurações do `launch.json`
3. Verificar se o programa foi compilado com `-g`

### Logs Úteis
```bash
# Verificar extensões instaladas
code --list-extensions

# Verificar configurações
code --list-extensions --show-versions

# Abrir VSCode em modo verbose
code --verbose
```

## 📚 Recursos Adicionais

### Documentação
- [VSCode Extensions](https://code.visualstudio.com/docs/editor/extension-gallery)
- [C/C++ Extension](https://marketplace.visualstudio.com/items?itemName=ms-vscode.cpptools)
- [Extension API](https://code.visualstudio.com/api)

### Comunidade
- [VSCode Marketplace](https://marketplace.visualstudio.com/)
- [GitHub Extensions](https://github.com/topics/vscode-extension)
- [Stack Overflow](https://stackoverflow.com/questions/tagged/visual-studio-code)

---

*Extensões otimizadas para desenvolvimento em C com VSCode* 