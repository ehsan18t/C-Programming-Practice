<div align="center">
<h1 align="center">Beginner Vim Cheatsheet for Beginners </h1>

### These commands are tested in `VSCode` with `Vim plugin`.
</div>

&nbsp;
### 💠 Mode
* `ESC` / `Ctrl + [` - Normal Mode
* `a` - Insert Mode (After Current Char)
* `i` - Insert Mode (Before Current Char)
* `v` - Visual Mode / Selection Mode
* `:` - Command Mode

&nbsp;
### 💠 Arrow
* `h` - Left arrow
* `l` - Right arrow
* `j` - Down arrow
* `k` - Up arrow

&nbsp;
### 💠 Search
* `/pattern` - Search forword
* `?pattern` - Search backword
* `n` - Repeat search forword
* `N` - Repeat search backword

&nbsp;
### 💠 Jump / Hop
#### **`Word`**
* `e` - Last char before space
* `w` - Next word (first char)
* `b` - Previous word (first char)
* `ge` - Previous Word (last char)
* `*` - Next same word
* `#` - Previous same word

&nbsp;
#### **`Line`**
* `0` - Start of the line
* `^` - Start of the line (after whitespace)
* `I` - Start of the line and insert (after whitespace)
* `$` - End of the line
* `A` - End of the line and insert
* `o` - Next line and insert
* `O` - Previous line and insert
* `gg` - First line
* `G` - Last line
* `:n` - Goto n line
* `nG` - Goto n line

&nbsp;
#### **`Window`**
* `zz` - Center this line
* `zt` - Top this line
* `zb` - Bottom this line
* `H` - Top of screen
* `M` - Middle of screen
* `L` - Bottom of screen

&nbsp;
#### **`Tab`**
* `:tabclose` - Close current tab
* `:tabfirst` - First tab
* `:tablast` - Last tab
* `:tabn` - Next tab
* `tabp` - Previous tab

&nbsp;

### 💠 Select
* `ve` - Select untill next space
* `vw` - Select untill next word
* `V` - Select current line
* `v` - Select current char

&nbsp;

### 💠 Copy
* `yy` - Copy current line
* `y` - Copy selected (Only in visual mode)
* `yw` - Copy word
* `yj` - Copy current and previous line
* `yk` - Copy current and next line

&nbsp;

### 💠 Editing
#### **`Paste`**
* `p` - Paste next 
* `P` - Paste Previous

&nbsp;
#### **`Delete`**
* `dd` - Delete line
* `dw` - Delete current word
* `s` - Delete current char and insert
* `S` - Delete current line and insert
* `C` - Delete until end of line and insert 

&nbsp;
#### **`Undo/Redo`**
* `u` - Undo changes
* `Ctrl + c + r` - Redo






&nbsp;
## 💠 Important VSCode Configuaration for New Users
#### **Disable Vim `ctrl+c` `ctrl+v` `ctrl+x` commands in VSCode**
```json
"vim.handleKeys": {
		"<C-c>": false,
		"<C-x>": false,
		"<C-v>": false
	}
```