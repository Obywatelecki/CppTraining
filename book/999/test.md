
[PlantUML](http://plantuml.com/)

{% plantuml %}

Source --> Precompiled
Precompiled --> Object
Object --> Executable

main.cpp --> main.i
main.i --> main.obj
main.obj --> main.exe

[*] --> State1
State1 -> [*]
State1 -> State2
State2 -> [*]
State1 : this is a string
State1 : this is another string


  
{% endplantuml %}
