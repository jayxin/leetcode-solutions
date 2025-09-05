# LeetCode Solutions

- `with-number`: LeetCode Problems with number.
- `no-number`: LeetCode Problems without number.
- `scripts`: Scripts to compile, run and diff.
- `tpl-c`: Template for C.
- `tpl-cc`: Template for CPP.
- `utils`: Helper data structures and algorithms.
- `comment.vim`: A vimscript file to comment/uncomment different versions of
solution of a LeetCode Problem.

## Usage of comment.vim

Open Vim and type the command `:so comment.vim`.

Different solutions are delimited by version sign like `#v1`.

```c
// #v1
void hello() {
    printf("hello v1!\n");
}
// #v1

//// #v2
//void hello() {
//    printf("hello v2!\n");
//}
//// #v2
```

You can use `<leader>vc` and type `#v1` to comment the code bounded
by `#v1`.

You can use `<leader>vu` and type `#v2` to uncomment the code bounded
by `#v2`.

`<leader>vs` is used to select and yank the corresponding version of code.
