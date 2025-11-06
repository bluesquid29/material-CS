# Example 

```
{trigger: "\\sum", replacement: "\\sum_{${0:i}=${1:1}}^{${2:N}} $3", options: "m"},
```

Show as below 

```
{
  trigger: "\\sum",           // What you type to activate
  replacement: "...",         // What gets inserted
  options: "m"                // Where it works
}
```

---

## 1. **Trigger**: `"\\sum"`
- When you type `\sum` (the LaTeX sum command), this snippet activates
- The `\\` is an escaped backslash (remember: `\` is special, so `\\` means literal `\`)

---

## 2. **Replacement**: `"\\sum_{${0:i}=${1:1}}^{${2:N}} $3"`

This is what gets inserted, with **tabstops** for quick editing:
```
\sum_{i=1}^{N} 
     ↑ ↑ ↑   ↑
     0 1 2   3
```

$$

$$
### Tabstops Explained:
- `${0:i}` → Tabstop 0 (final cursor position), defaults to `i`
- `${1:1}` → Tabstop 1, defaults to `1`
- `${2:N}` → Tabstop 2, defaults to `N`
- `$3` → Tabstop 3 (cursor lands here after filling in 0, 1, 2)

### How it works when you use it:
1. Type `\sum` → snippet triggers
2. Gets replaced with: `\sum_{i=1}^{N} ` with `i` selected
3. Press Tab → jumps to `1`, you can change it to another starting value
4. Press Tab → jumps to `N`, you can change the upper limit
5. Press Tab → cursor moves after the sum, ready to type the expression

---

## 3. **Options**: `"m"`
- `m` = **Math mode only**
- This snippet only activates when you're inside LaTeX math delimiters like `$...$` or `$$...$$`

---

## Visual Example

**You type:**
```
$\sum
```

**Becomes:**
```
$\sum_{i=1}^{N} █
      └─selected
```

**After pressing Tab twice and typing "x":**
```
$\sum_{k=0}^{\infty} x
```



### 

### Greek letters

| L-Trigger | Lowercase   | Symbol        | U-Trigger | Uppercase | Symbol     | Letter      |
| --------- | ----------- | ------------- | --------- | --------- | ---------- | ----------- |
| @a        | \alpha      | $\alpha$      |           |           |            | Alpha       |
| @b        | \beta       | $\beta$       |           |           |            | Beta        |
| @g        | \gamma      | $\gamma$      | @G        | \Gamma    | $\Gamma$   | Gamma       |
| @d        | \delta      | $\delta$      | @D        | \Delta    | $\Delta$   | Delta       |
| @e        | \epsilon    | $\epsilon$    |           |           |            | Epsilon     |
| :e        | \varepsilon | $\varepsilon$ |           |           |            | Var Epsilon |
| @z        | \zeta       | $\zeta$       |           |           |            | Zeta        |
| @t        | \theta      | $\theta$      | @T        | \Theta    | $\Theta$   | Theta       |
| :t        | \vartheta   | $\vartheta$   |           |           |            | Var Theta   |
| @i        | \iota       | $\iota$       |           |           |            | Iota        |
| @k        | \kappa      | $\kappa$      |           |           |            | Kappa       |
| @l        | \lambda     | $\lambda$     | @L        | \Lambda   | $\Lambda$  | Lambda      |
| @s        | \sigma      | $\sigma$      | @S        | \Sigma    | $\Sigma$   | Sigma       |
| @u        | \upsilon    | $\upsilon$    | @U        | \Upsilon  | $\Upsilon$ | Upsilon     |
| @o, ome   | \omega      | $\omega$      | @O, Ome   | \Omega    | $\Omega$   | Omega       |

**Note:** All triggers use `options: "mA"` (math mode, auto-expand)

$$
fd\f\d\f\d\f\d\f\d\d\cvcvc \beta d alpha \alpha df
e\e\e\e\e\e\e\e\e\e\e\a\h\p\l\a\
$$


These are **snippet options** that control when and how the snippet triggers. Here's what each letter means:

## Option Flags

| Flag  | Meaning           | Description                                          |
| ----- | ----------------- | ---------------------------------------------------- |
| **t** | **text mode**     | Triggers in regular text (outside math)              |
| **m** | **math mode**     | Triggers inside math delimiters ($...$, \$\$...\$\$) |
| **A** | **auto-expand**   | Triggers automatically as you type (no tab needed)   |
| **r** | **regex**         | Trigger is treated as a regular expression           |
| **w** | **word boundary** | Only triggers at word boundaries                     |
| **n** | **no auto**       | Requires manual trigger (usually Tab)                |

## Common Combinations

|Option|What it means|
|---|---|
|**mA**|Math mode + Auto-expand (triggers automatically in math)|
|**tA**|Text mode + Auto-expand (triggers automatically in text)|
|**mAr**|Math mode + Auto + Regex pattern|
|**tAw**|Text mode + Auto + Word boundary|
|**m**|Math mode only, needs Tab to expand|
|**tMA**|Text mode + Math mode + Auto (works everywhere)|

## Examples from Your Snippets

```javascript
{trigger: "mk", replacement: "$$0$", options: "tA"}
// Text mode, auto-expand: typing "mk" in text automatically creates $...$

{trigger: "dm", replacement: "$$\n$0\n$$", options: "tAw"}
// Text mode, auto-expand, word boundary: "dm" only triggers as separate word

{trigger: "@a", replacement: "\\alpha", options: "mA"}
// Math mode, auto-expand: typing "@a" inside $...$ automatically becomes \alpha

{trigger: "([a-zA-Z])bar", replacement: "\\overline{[[0]]}", options: "mAr"}
// Math mode, auto-expand, regex: "xbar" → \overline{x}
```

## Why This Matters

- **mA** prevents Greek letters from triggering in regular text (you don't want "@a" → "\alpha" in prose)
- **tA** lets you quickly enter math mode without extra keystrokes
- **w** prevents accidental triggers (e.g., "Adam" won't trigger "dm")

---
---
---

This is a **regex-based auto-subscript snippet** that automatically converts letter-number combinations into LaTeX subscripts.

## Breakdown

```javascript
{
  trigger: /([A-Za-z])(\d)/,           // Regex pattern
  replacement: "[[0]]_{[[1]]}",         // What it becomes
  options: "rmA",                       // Regex + Math + Auto
  description: "Auto letter subscript",
  priority: -1                          // Low priority
}
```

---

## How It Works

### Trigger: `/([A-Za-z])(\d)/`

- `([A-Za-z])` - Capture group 0: Any letter (a-z or A-Z)
- `(\d)` - Capture group 1: Any digit (0-9)
- Pattern matches: letter immediately followed by a number

### Replacement: `"[[0]]_{[[1]]}"`

- `[[0]]` - First capture group (the letter)
- `_{[[1]]}` - Subscript with second capture group (the digit)

### Options: `"rmA"`

- `r` = **Regex** pattern
- `m` = **Math mode** only
- `A` = **Auto-expand** immediately

### Priority: `-1`

- **Lower priority** than default (0)
- If multiple snippets match, this one triggers last
- Prevents it from overriding more specific patterns

---

## Examples in Action

|You Type|Becomes|Renders As|
|---|---|---|
|`x1`|`x_{1}`|$x_{1}$|
|`a0`|`a_{0}`|$a_{0}$|
|`y2`|`y_{2}`|$y_{2}$|
|`N5`|`N_{5}`|$N_{5}$|
|`alpha2`|`alpha_{2}`|(if no other snippet catches it first)|

---

## Why Priority = -1?

Prevents conflicts with other snippets. For example:

```javascript
// Higher priority (default 0):
{trigger: "(${GREEK})(\\d)", replacement: "\\[[0]]_{[[1]]}", options: "mAr"}

// Lower priority (-1):
{trigger: /([A-Za-z])(\d)/, replacement: "[[0]]_{[[1]]}", options: "rmA", priority: -1}
```

**If you type `alpha2`:**

1. First snippet matches: `alpha2` → `\alpha_{2}` ✓
2. Second snippet doesn't run (lower priority)

**If you type `x2`:**

1. First snippet doesn't match (not a Greek letter)
2. Second snippet runs: `x2` → `x_{2}` ✓

---

## Summary

This snippet is a **convenience feature** that automatically subscripts any letter-number combination in math mode, making it faster to type expressions like $x_1, y_2, z_3$ without manually typing the underscore and braces each time! 🚀