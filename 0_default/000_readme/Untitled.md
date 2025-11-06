


{
  trigger: /([^\\])(exp|log|ln)/,  // Regex pattern
  replacement: "[[0]]\\[[1]]",      // What it becomes
  options: "rmA"                    // Regex + Math + Auto
}


---

## How It Works

### Trigger: `/([^\\])(exp|log|ln)/`

- `([^\\])` - Capture group 0: Any character that is **NOT** a backslash
  - `[^\\]` means "not `\`"
- `(exp|log|ln)` - Capture group 1: The word `exp`, `log`, OR `ln`

### Replacement: `"[[0]]\\[[1]]"`

- `[[0]]` - The character before the function
- `\\[[1]]` - Backslash + the function name

---

## Examples in Action

| You Type         | Trigger Matches    | Becomes               | Renders As            |           |
| ---------------- | ------------------ | --------------------- | --------------------- | --------- |
| `xexp`           | `x` + `exp`        | `x\exp`               | $x\exp$               |           |
| `2log`           | `2` + `log`        | `2\log`               | $2\log$               |           |
| ` ln`            | ` ` (space) + `ln` | ` \ln`                | $\ln$                 |           |
| `(exp`           | `(` + `exp`        | `(\exp`               | $(\exp$               |           |
| `\exp`           | ❌ No match         | `\exp`                | (unchanged)           |           |
| p`space`->q      |                    |                       | $$                    |           |
| p`space`<->q     |                    | `p \leftrightarrow q` | $p \leftrightarrow q$ |           |
|                  |                    |                       |                       |           |
| A`space`andB     |                    | `A \cap B`            | $A \cap B$            |           |
| A`space`orrB     |                    | `A \cup B`            | $A \cup B$            |           |
| x`space`inneset  |                    | `x \in \emptyset`     | $x \in \emptyset$     |           |
| x`space`notinB   |                    | `x \not\in B`         | $x \not\in B$         |           |
| \\\\\            |                    | `\setminus`           |                       | mathblock |
| A`space`sub=B    |                    | `A \subseteq B`       | $A \subseteq B$       |           |
| A`space`sup=B    |                    | `A \supseteq B`       | $A \supseteq B$       |           |
| V`space`=`space` |                    |                       |                       |           |

|                               |                  |
| ----------------------------- | ---------------- |
| V`spa`=`spa`seta,`spa`b,`spa` | $V = \{ a,b \} $ |

$$
x \in \emptyset
$$
---
$$
x^{2} + y^{2} = z^{2}
$$

$$
\begin{align}
dfek;;jlk \\
dfjlasef \\
djfle;asejlf \\
dfda
\end{align}
$$
## Why `[^\\]`? (The NOT Backslash Part)

**Problem:** Without this check, it would trigger on already-escaped functions:
```
\exp  →  \\exp  (double backslash - WRONG!)
```

**Solution:** Only trigger if the character before is NOT a backslash:
```
xexp  →  x\exp  ✓
\exp  →  \exp   ✓ (no change, already correct)
```

---

## Visual Example

**Typing in real-time:**
```
You type:  2 l o g ( x )
Step 1:    2 l o g
                 ↑ - "g" is preceded by "o", matches? No
Step 2:    2 l o g (
                   ↑ - "(" precedes nothing yet
           Actually: " log" where " " (space) + "log" matches!
Result:    2 \log(x)


