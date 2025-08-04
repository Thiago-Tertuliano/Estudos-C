# Vim/Neovim para Desenvolvimento em C

## 🎯 Visão Geral

O Vim/Neovim é um editor de texto altamente customizável e eficiente. É ideal para desenvolvimento avançado, especialmente em servidores e para usuários que preferem interface baseada em texto.

## 📋 Pré-requisitos

### 1. Instalar Vim/Neovim
```bash
# Ubuntu/Debian
sudo apt update
sudo apt install vim neovim

# CentOS/RHEL
sudo yum install vim neovim

# macOS
brew install vim neovim

# Windows
# Baixar do site oficial ou usar WSL
```

### 2. Verificar Instalação
```bash
# Verificar versão do Vim
vim --version

# Verificar versão do Neovim
nvim --version

# Verificar se o compilador está funcionando
gcc --version
```

## 🚀 Configuração Inicial

### 1. Primeira Execução
1. Abra o Vim/Neovim
2. Digite `:help` para ver a documentação
3. Configure o arquivo `.vimrc` ou `init.vim`
4. Teste com um programa simples

### 2. Configurações Básicas
Crie um arquivo `.vimrc` (Vim) ou `init.vim` (Neovim):

```vim
" Configurações básicas
set number
set relativenumber
set autoindent
set smartindent
set tabstop=4
set shiftwidth=4
set expandtab
set showmatch
set ignorecase
set smartcase
set incsearch
set hlsearch
set syntax=on
set filetype=on
set encoding=utf-8
set termencoding=utf-8
set fileencoding=utf-8
```

## ⚙️ Configurações Avançadas

### 1. Configurações para C
```vim
" Configurações específicas para C
autocmd FileType c setlocal:
    \ tabstop=4
    \ shiftwidth=4
    \ expandtab
    \ autoindent
    \ smartindent
    \ cindent
    \ formatoptions=croql
    \ comments=sr:/*,mb:*,el:*/,://
    \ cinoptions=:0,l1,t0,g0

" Compilação e execução
autocmd FileType c nnoremap <F9> :!gcc -Wall -Wextra -std=c99 -g % -o %:r && ./%:r<CR>
autocmd FileType c nnoremap <F10> :!./%:r<CR>
autocmd FileType c nnoremap <F11> :!gdb %:r<CR>
```

### 2. Configurações do Editor
```vim
" Interface
set guifont=Consolas:h12
set guioptions-=T
set guioptions-=m
set guioptions-=r
set guioptions-=L

" Navegação
set mouse=a
set scrolloff=5
set sidescrolloff=5

" Busca
set gdefault
set magic
set showmatch
set matchtime=2
```

### 3. Configurações do Debugger
```vim
" Debug com GDB
autocmd FileType c nnoremap <F8> :!gdb %:r<CR>
autocmd FileType c nnoremap <F7> :!gcc -g % -o %:r<CR>
```

## 🔧 Uso Básico

### 1. Criar Arquivo C
```bash
# Abrir Vim/Neovim
vim programa.c
# ou
nvim programa.c
```

### 2. Modos do Vim
- **Normal**: Navegação e comandos
- **Insert**: Edição de texto
- **Visual**: Seleção de texto
- **Command**: Comandos

### 3. Comandos Básicos
```vim
" Navegação
h, j, k, l          " Mover cursor
w, b                " Mover por palavras
0, $                " Início/fim da linha
gg, G               " Início/fim do arquivo

" Edição
i, a                " Inserir antes/depois
I, A                " Inserir no início/fim da linha
o, O                " Nova linha abaixo/acima
x, dd               " Deletar caractere/linha
yy, p               " Copiar/colar linha

" Busca
/pattern            " Buscar para frente
?pattern            " Buscar para trás
n, N                " Próximo/anterior

" Salvamento
:w                  " Salvar
:q                  " Sair
:wq                 " Salvar e sair
:q!                 " Sair sem salvar
```

### 4. Compilar e Executar
```vim
" Compilar
:!gcc -Wall -Wextra -std=c99 -g % -o %:r

" Executar
:!./%:r

" Compilar e executar
:!gcc -Wall -Wextra -std=c99 -g % -o %:r && ./%:r
```

## 📁 Estrutura de Projeto

### Projeto Simples
```
projeto/
├── main.c
├── utils.c
├── utils.h
├── Makefile
└── .vimrc
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
├── Makefile
└── .vimrc
```

## 🛠️ Comandos Úteis

### Atalhos de Teclado
- `i` - Modo insert
- `v` - Modo visual
- `V` - Modo visual linha
- `Ctrl+v` - Modo visual bloco
- `Esc` - Voltar ao modo normal
- `:w` - Salvar
- `:q` - Sair
- `:wq` - Salvar e sair
- `:q!` - Sair sem salvar

### Comandos do Terminal
```bash
# Abrir arquivo
vim arquivo.c

# Abrir múltiplos arquivos
vim arquivo1.c arquivo2.c

# Abrir em modo somente leitura
vim -R arquivo.c

# Abrir em modo diff
vimdiff arquivo1.c arquivo2.c
```

## 🔍 Recursos Avançados

### 1. Plugins Úteis
```vim
" Plugin Manager (vim-plug)
call plug#begin('~/.vim/plugged')

" Syntax highlighting
Plug 'vim-syntastic/syntastic'

" Auto-completion
Plug 'neoclide/coc.nvim'

" File explorer
Plug 'scrooloose/nerdtree'

" Git integration
Plug 'tpope/vim-fugitive'

" Comment tools
Plug 'scrooloose/nerdcommenter'

" Status line
Plug 'vim-airline/vim-airline'

call plug#end()
```

### 2. Configurações de Plugin
```vim
" Syntastic (syntax checking)
let g:syntastic_c_checkers = ['gcc']
let g:syntastic_c_compiler_options = '-Wall -Wextra -std=c99'

" NERDTree
map <C-n> :NERDTreeToggle<CR>

" NERDCommenter
map <C-_> <leader>c<space>
```

### 3. Debugging
```vim
" Debug com GDB
autocmd FileType c nnoremap <F8> :!gdb %:r<CR>

" Breakpoints
autocmd FileType c nnoremap <F7> :!gcc -g % -o %:r<CR>
```

## 🐛 Solução de Problemas

### Problemas Comuns

#### 1. Vim não abre
1. Verificar se Vim está instalado
2. Verificar permissões
3. Verificar dependências

#### 2. Configurações não funcionam
1. Verificar arquivo `.vimrc`
2. Verificar sintaxe
3. Recarregar Vim

#### 3. Plugins não carregam
1. Verificar plugin manager
2. Verificar dependências
3. Verificar configurações

#### 4. Compilação não funciona
1. Verificar se GCC está instalado
2. Verificar configurações
3. Verificar permissões

### Logs Úteis
```bash
# Verificar versão do Vim
vim --version

# Verificar configurações
vim -c 'set all' -c 'q'

# Verificar plugins
vim -c 'scriptnames' -c 'q'
```

## 📚 Recursos Adicionais

### Documentação
- [Vim Documentation](https://vimhelp.org/)
- [Neovim Documentation](https://neovim.io/doc/)
- [GCC Manual](https://gcc.gnu.org/onlinedocs/)

### Comunidade
- [Vim Stack Exchange](https://vi.stackexchange.com/)
- [Stack Overflow](https://stackoverflow.com/questions/tagged/vim)
- [Reddit r/vim](https://www.reddit.com/r/vim/)

### Plugins Úteis
- **Syntastic**: Syntax checking
- **Coc.nvim**: Auto-completion
- **NERDTree**: File explorer
- **Fugitive**: Git integration
- **NERDCommenter**: Comment tools

## 🎯 Dicas de Produtividade

### 1. Macros
```vim
" Macro para função main
let @m = 'i#include <stdio.h>^M#include <stdlib.h>^M^Mint main() {^M    ^M    return 0;^M}^['
```

### 2. Snippets
```vim
" Snippet para função
autocmd FileType c inoremap <C-f> void function_name() {<CR>}<Esc>k$F)i
```

### 3. Debugging
- Use breakpoints no código
- Monitore variáveis
- Use o call stack

### 4. Organização
- Mantenha arquivos organizados
- Use nomes descritivos
- Documente seu código
- Use comentários adequados

## 🚀 Próximos Passos

1. **Explore recursos**: Teste diferentes funcionalidades
2. **Configure plugins**: Instale e configure plugins úteis
3. **Crie macros**: Desenvolva macros personalizadas
4. **Organize projetos**: Aprenda a gerenciar projetos complexos
5. **Integre ferramentas**: Use ferramentas externas quando necessário

## 📝 Configurações Recomendadas

### Para Iniciantes
```vim
" Configurações básicas
set number
set autoindent
set tabstop=4
set shiftwidth=4
set expandtab
set syntax=on
set filetype=on

" Compilação simples
autocmd FileType c nnoremap <F9> :!gcc -Wall -Wextra -std=c99 -g % -o %:r && ./%:r<CR>
```

### Para Desenvolvimento
```vim
" Configurações avançadas
set number
set relativenumber
set autoindent
set smartindent
set tabstop=4
set shiftwidth=4
set expandtab
set showmatch
set ignorecase
set smartcase
set incsearch
set hlsearch
set syntax=on
set filetype=on
set encoding=utf-8

" Plugins e ferramentas
call plug#begin('~/.vim/plugged')
Plug 'vim-syntastic/syntastic'
Plug 'neoclide/coc.nvim'
Plug 'scrooloose/nerdtree'
Plug 'tpope/vim-fugitive'
call plug#end()

" Compilação e debug
autocmd FileType c nnoremap <F9> :!gcc -Wall -Wextra -std=c99 -g % -o %:r && ./%:r<CR>
autocmd FileType c nnoremap <F8> :!gdb %:r<CR>
```

---

*Configuração otimizada para desenvolvimento em C com Vim/Neovim* 