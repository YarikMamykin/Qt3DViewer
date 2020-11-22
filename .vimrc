let $VIM_BUILD_FOLDER='build'
let $VIM_SRC_FOLDER='..'
let $COMPILE_COMMANDS_JSON='compile_commands.json'

function! TagIt()
  silent !clear
  silent !rm -frv tags 
  silent !echo "Building tags..."
  silent !find . -name '*.c' -o -name "*.cc" -o -name '*.cpp' -o -name '*.h' -o -name '*.hpp' > project.files
  silent !find /usr/include/qt/ -name '*.c' -o -name "*.cc" -o -name '*.cpp' -o -name '*.h' -o -name '*.hpp' > project.files
  silent !cat project.files | ctags --verbose=yes --sort=yes --c++-kinds=+p --fields=+iaS --extras=+q --language-force=C++ -f tags -L -
  silent !rm -frv project.files
  silent !echo "Done"
  redraw!
endfunction

function! Build()
  !mkdir -p $VIM_BUILD_FOLDER && cd $VIM_BUILD_FOLDER && rm -frv * && qmake $VIM_SRC_FOLDER && make -j${CORES};
  redraw!
endfunction

function! QuickBuild()
  !mkdir -p $VIM_BUILD_FOLDER && cd $VIM_BUILD_FOLDER && qmake $VIM_SRC_FOLDER && make -j${CORES};
  redraw!
endfunction

function! LinkCompileCommands()
  silent !mkdir -p $VIM_BUILD_FOLDER && cd $VIM_BUILD_FOLDER && rm -frv * && cmake $VIM_SRC_FOLDER -DCMAKE_EXPORT_COMPILE_COMMANDS=YES && ln -sf $(find ./${VIM_BUILD_FOLDER}/ -name "$COMPILE_COMMANDS_JSON") ./$COMPILE_COMMANDS_JSON
  redraw!
endfunction

function! Run()
  !cd $VIM_BUILD_FOLDER && if [ -f "Qt3DViewer" ]; then ./Qt3DViewer; fi
  redraw!
endfunction

function! Debug()
  !cd $VIM_BUILD_FOLDER && if [ -f "Qt3DViewer" ]; then gdb ./Qt3DViewer; fi
  redraw!
endfunction

nmap <F4> :call LinkCompileCommands()<CR>:call TagIt()<CR>
nmap <Leader><F4> :call QuickBuild()<CR>
nmap <Leader><F5> :call Run()<CR>
nmap <Leader><F6> :call Debug()<CR>
autocmd! BufNewFile,BufRead,BufEnter *.qml nmap <Leader><F5> :!qmlscene-qt5 %<CR>

function! Switch()
  let filename = expand("%:t:r")
  let fileext = expand("%:e")
  if (fileext == "cpp")
    find %:t:r.h
  endif
  if (fileext == "h")
    find %:t:r.cpp
  endif
endfunction

set shell=/bin/bash
set wildignore+=./build/**
set wildignore+=./build/
