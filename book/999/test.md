
[PlantUML](http://plantuml.com/)

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
