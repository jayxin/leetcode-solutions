function! s:IsVersionComment(line_start, versionSign)
  let line_content = getline(a:line_start)
  let is_vcomment = match(line_content, "/\\{4}\\s*" .. a:versionSign)

  if is_vcomment != -1
    return "yes"
  endif
  return "no"
endfunction

function! s:VersionUncomment(versionSign)
  " find line range
  exe cursor(1, 1)
  let line_start = search(a:versionSign)
  let line_end = search(a:versionSign)

  if line_start == 0
    echo "Version " .. a:versionSign .. " is not defined!"
    return
  endif

  if s:IsVersionComment(line_start, a:versionSign) == "no"
    echo "Version " .. a:versionSign .. " has been uncommented! Do nothing."
    return
  endif

  exe "normal zR"
  exe ':' string(line_start) .. ',' .. string(line_end) .. 'norm ^2x'
endfunction

function! s:VersionComment(versionSign)
  " find line range
  exe cursor(1, 1)
  let line_start = search(a:versionSign)
  let line_end = search(a:versionSign)

  if line_start == 0
    echo "Version " .. a:versionSign .. " is not defined!"
    return
  endif

  if s:IsVersionComment(line_start, a:versionSign) == "yes"
    echo "Version " .. a:versionSign .. " has been commented! Do nothing."
    return
  endif

  exe "normal zR"
  exe ':' string(line_start) .. ',' .. string(line_end) .. 'norm I//'
endfunction

function! s:SelectVersion(versionSign)
  " find line range
  exe cursor(1, 1)
  let line_start = search(a:versionSign)
  let line_end = search(a:versionSign)
  exe 'norm ' line_start .. "gg" .. "V" .. line_end .. "gg"
  exe 'norm y'
endfunction

function! VersionCommentWrapper(type)
  let versionSign = input("Input the sign of version: ", "")
  echo "\n"
  "if versionSign == ""
  if match(versionSign, "^\\s*$") != -1
    "echo "Empty version sign!"
    return
  endif

  if a:type == '0'
    call s:VersionComment(versionSign)
  elseif a:type == '1'
    call s:VersionUncomment(versionSign)
  elseif a:type == '2'
    call s:SelectVersion(versionSign)
  endif
endfunction

" Command Definition
:command -nargs=0 Vcomment call VersionCommentWrapper('0')
:command -nargs=0 Vuncomment call VersionCommentWrapper('1')
:command -nargs=0 Vselect call VersionCommentWrapper('2')

" KeyMap Definition
nnoremap <leader>vc <Cmd>Vcomment<CR>
nnoremap <leader>vu <Cmd>Vuncomment<CR>
nnoremap <leader>vs <Cmd>Vselect<CR>
