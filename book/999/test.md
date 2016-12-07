
[PlantUML](http://plantuml.com/)
[PlantUML server](http://www.plantuml.com/plantuml)

{% plantuml %}

[*] --> Source
Source --> Precompiled
Precompiled --> Object
Object --> Executable

main.cpp --> main.i
main.i --> main.obj
main.obj --> main.exe
main.obj : this is a string

{% endplantuml %}
