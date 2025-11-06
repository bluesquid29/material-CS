# Thing (css)

italic 修改成 normal

```css
/* Blockquote */
body:not(.default-font-color) .markdown-preview-view blockquote,
body:not(.default-font-color) span.cm-quote.cm-quote-1 {
  font-style: italic;
  color: var(--quote-color);
}
```