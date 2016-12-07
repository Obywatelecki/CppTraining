
[PlantUML](http://plantuml.com/)
[PlantUML server](http://www.plantuml.com/plantuml)

{% plantuml %}

state "main<source>"     as Source_main
state "<preprocessed>"   as Preprocessed_main

state "myFunc<source>"   as Source_myFunction
state "<preprocessed>"   as Preprocessed_myFunction

state "main<object>"     as Object_main
state "myFunc<object>"   as Object_myFunction
state "main<executable>" as Executable

[*]                     --> Source_main
Source_main             --> Preprocessed_main       : preprocessor
Preprocessed_main       --> Object_main             : compiler

[*]                     --> Source_myFunction
Source_myFunction       --> Preprocessed_myFunction : preprocessor
Preprocessed_myFunction --> Object_myFunction       : compiler 

Object_main             --> Executable              : linker
Object_myFunction       --> Executable              : linker
stdlib                  --> Executable              : linker
Executable              --> [*]

Source_main             : App1.cpp
Preprocessed_main       : App1.i

Source_myFunction       : myFunc.cpp
Preprocessed_myFunction : myFunc.i

Object_main             : App1.obj
Object_myFunction       : myFunc.obj
Executable              : App1.exe

{% endplantuml %}
