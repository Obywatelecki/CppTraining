[Diagram sekwencji](https://bramp.github.io/js-sequence-diagrams/)

```sequence
Title: Here is a title
A->B: Normal line
B-->C: Dashed line
C->>D: Open arrow
D-->>A: Dashed open arrow
```

---

[PlantUML](http://plantuml.com/)

{% plantuml %}
Bob->Alice : hello
{% endplantuml %}

```uml
Bob->Alice : hello
```

---

[Flow](https://plugins.gitbook.com/plugin/flow)

{% flow %}
st=>start: Start:>http://www.google.com[blank]
e=>end:>http://www.google.com
op1=>operation: My Operation
sub1=>subroutine: My Subroutine
cond=>condition: Yes
or No?:>http://www.google.com
io=>inputoutput: catch something...

st->op1->cond
cond(yes)->io->e
cond(no)->sub1(right)->op1
{% endflow %}

{% flowchart %}
st=>start: Start:>http://www.google.com[blank]
e=>end:>http://www.google.com
op1=>operation: My Operation
sub1=>subroutine: My Subroutine
cond=>condition: Yes
or No?:>http://www.google.com
io=>inputoutput: catch something...

st->op1->cond
cond(yes)->io->e
cond(no)->sub1(right)->op1
{% endflowchart %}