<%*
const content = tp.file.content
const headings = content.match(/^#+\s.+$/gm) || []
tR += headings.join("\n")
%>
