# ESTRUCTURAS DE DATOS Y ALGORITMOS II, 2022-2023
## JAJAGRAM, Centrada en chistes
Creada por:
 - Marcel Medina Mestre, 
 - Gori Ribot Sansó,
 - Shuangjie Xia, 

---

## 1. INTRODUCCIÓN
Hemos emprendido el desafío de crear una red social centrada en chistes, y a lo largo del proceso, hemos enfrentado dificultades y aprendido valiosas lecciones.

Hemos aprendido cómo implementar diferentes estructuras de datos, concretamente las pilas, las colas y las listas enlazadas. También nos hemos enfrentado a diferentes algoritmos, tanto lineales ``(LinearSearch)`` como secuenciales (``BubbleSort`` e ``InsertionSort``). Es decir hemos plasmado los conceptos que hemos aprendido en teoría en este proyecto y eso nos ha permitido consolidar nuestro aprendizaje y ver cómo se pueden implementar estos conceptos de forma práctica.

Además, al ser un trabajo colectivo, también hemos aprendido a como trabajar conjuntamente como programadores para completar un proyecto. También a nivel individual hemos mejorado nuestros conocimientos de programación y hemos aprendido lo importante que es estructurar bien un código y mantenerlo lo más limpio posible para facilitar su comprensión y evitar futuros errores. 

En resumen, este proyecto ha sido muy útil como primer contacto con el mundo de la programación, ya que ha implicado muchas horas, el uso de diferentes estructuras de datos y algoritmos, y además nos ayudado a comprender mejor cómo se debe estructurar un código, y a cómo trabajar de manera conjunta para un mismo objetivo.

## 2. Objetivos

### 2.1 Objetivos obligatorios alcanzados
**Lista (List), Pila (Stack) y Cola (Queue)**

En el caso de las listas, en nuestro proyecto hemos implementado varias listas enlazadas (para almacenar la lista de usuarios, la lista de publicaciones, la lista de solicitudes de amistad). Nos centraremos en explicar como funciona nuestra lista de usuarios. En nuestro caso en la estructura de usuario (que se encuentra en el fichero user.h) tenemos un puntero de la propia estructura de usuario que apunta al siguiente usuario de la fila. Además, en el fichero main, creamos el head de la lista, asignado como userList, al cual le asignamos NULL antes de que se inserte algún usuario. Luego, al implementar un usuario comprobamos si la lista está vacía (userList == NULL) y si es así, asignamos el usuario como head de la lista. 

En caso contrario vamos recorriendo la lista, a través del puntero next de cada usuario que apunta al siguiente usuario, hasta llegar al último usuario de la lista (que su puntero next sea NULL) y añadimos el nuevo usuario como el último de la lista (asignamos NULL a su next, y al que era el último usuario le asigna como next el nuevo usuario). Crear esta lista nos ha llevado aproximadamente 1 hora.

Para implementar una cola, hemos aprovechado las solicitudes de amistad. Cada usuario, (en la estructura User del fichero user.h) tiene un atributo que es un puntero a una cola de solicitudes de amistad (estructura en user.h que contiene un puntero para el head y otro para el tail). Además cada estructura de solicitud de amistad(también se encuentra en el fichero user.h) contiene el nombre del receptor, el nombre del emisor y un puntero a la siguiente solicitud de amistad. 

Por un lado a la hora de implementar una nueva solicitud, a través de la función enqueue_friend_request (que se encuentra en el fichero user.c en la línea 190) se implementa nueva solicitud por el final. Por otro lado, con la función dequeue_friend_request (línea 202 de user.c) eliminamos la primera solicitud de la lista. Este algoritmo nos ha llevado aproximadamente 2 horas.

**Algoritmo de búsqueda** 

Un ejemplo en el que hemos usado un algoritmo de búsqueda lineal en nuestro proyecto es a la hora de buscar un usuario. Para esta funcionalidad hemos utilizado el algoritmo LinearSearch. Como ya hemos explicado anteriormente, nuestros usuarios están organizados en una lista enlazada. Para encontrar un usuario en la lista utilizamos la función find_user que se encuentra en el fichero user.c, en la línea 95. 

Esta función lo que hace básicamente es devolvernos la dirección de memoria en la que se encuentra el usuario que estamos buscando. Recibe como parámetros el head de la lista y el nombre del usuario. Luego, empezando por el head (y pasando al siguiente usuario a través del puntero next), va comparando el nombre de cada usuario con el nombre que ha recibido como parámetro, y si lo encuentra devuelve su posición en la memoria (si no existe devuelve NULL). De esta manera vamos recorriendo de manera lineal la lista de usuarios. Este algoritmo es bastante sencillo de implementar y nos llevó unos 15 minutos.

**Algoritmo de ordenación**

Un ejemplo en el que hemos utilizado el BubbleSort es en el diccionario. En nuestro proyecto al realizar una publicación, esta es sometida a un sistema de conteo, donde actualizamos el contador de cada palabra y añadimos las palabras nuevas. Luego, ordenamos descendentemente el diccionario utilizando el algoritmo BubbleSort de manera que las palabras que aparecen más veces quedan en las primeras posiciones del diccionario.La función en la que aplicamos BubbleSort es sort_word_frequency_word (línea 329 del archivo user.c). 

Esta función lo que hace es recorrer el diccionario y comparar cada elemento con el siguiente e intercambiarlos si el segundo es mayor que el primero. Va repitiendo el algoritmo hasta que el diccionario está totalmente ordenado. Para recorrer la lista, lo hace a través del algorimto LinearSearch, donde el puntero head está definido en el main.c como counter_dictionary y luego cada elemento del diccionario (definido como WordFrequencyCounter en user.h) contiene un puntero al próximo elemento del diccionario, y de esta manera va recorriendo el diccionario  Este algoritmo nos ha llevado 1 hora.

**Diccionario:**

En nuestro caso hemos implementado un diccionario, donde almacenamos todas las palabras que aparecen en las publicaciones y las veces que aparecen. Para ello hemos utilizado diversas funciones y estructuras de datos. En primer lugar, en el archivo user.h, tenemos la estructura WordFrequencyCounter, que representa un elemento del diccionario, y que tiene como atributos, la palabra, las veces que aparece y un puntero al siguiente elemento. Además, en el main.c, hemos creado el puntero al primer elemento del diccionario, que se llama counter_dictionary. Luego, al añadir una publicación, la sometemos a un sistema de conteo, a través de la función frequency_word_count (línea 277, archivo user.c), que recibe el puntero de la publicación y el puntero counter_dictionary, y lo que hace es que para cada palabra de la publicación la compara con todas las del diccionario para comprobar si se encuentra en el diccionario. 

En caso de que se encuentre en el diccionario actualiza su contador. Además con la función swap_word_frequency_counter ordenamos de manera descendente el diccionario utilizando el algoritmo BubbleSort. Además, con la función print_word_frequency_count podemos mostrar las 10 palabras más usadas en las publicaciones. Este algoritmo nos ha llevado unas 2 horas.

### 2.2 Objetivos deseables alcanzados
**Leer datos de una fuente externa**

En nuestro proyecto hemos implementado la opción de poder leer datos de un archivo de texto, concretamente, para poder añadir diversos usuarios a la red social.

Esta opción es posible gracias a la función read_user_from_txt_file que se encuentra en el archivo file_reader.c. Lo que hace esta funcion es abrir un archivo users.txt que tenemos en nuestro proyecto, donde cada línea representa un usuario y sus datos correspondientes, y para cada línea que lee crea un usuario y lo añade a la lista usuarios.

**Red Social fuera temática**

Nosotros hemos decidido apostar por una red social de chistes, donde cada usuario actua como un comediante. Además, las publicaciones de cada usuario son chistes, de manera que al agregar a usuarios y ver sus publicaciones, puedes ver los diferentes chistes que han publicado para pasar un buen rato y echarte unas risas. Si eres un persona con humor y que le gusta divertirse, esta va a ser tu red social favorita.

### 2.3. Objetivos exploratorios adquiridos

En nuestro proyecto tenemos una capa estética basada en colores. Al abrir la aplicación, aparece un texto en azul que da la bienvenida al usuario. Además, al aceptar una solicitud de amistad, aparece un mensaje en verde que confirma la acción, y si se rechaza la solicitud, aparece un mensaje en rojo. Es decir hemos complementado muchos mensajes con color para hacer la experiencia más agradable. El código para implementar esta capa estética se encuentra en el archivo printer.h.

## 3. SOLUCIÓN
**Arquitectura del sistema**

Para que la red funcione debidamente, hemos usado las siguientes partes de código: 

``main.c``

Es el fichero principal, en este fichero primero de todo inicializamos la lista de usuarios y el diccionario de palabras.Luego tenemos La estructura del main, donde está implementada la función showmenu que nos muestra el menú donde iremos eligiendo opciones para interactuar con el menú. 

``user.c/h``

En este archivo se encuentran la mayoria de nuestras funciones, Encontramos desde la  creación de usuarios, juntamente con las funciones que nos ayudan a hacer eso possible.
Tambien están las funciones de imprimir usuarios, encontrar usuarios y ordenar usuarios.
En el archivo, encontramos tambien las funciones relacionadas con las friend requests, que son el pilar de una red social, ya que sin poder interactuar con los usuarios no hay red social que exista. Podemos encontrar funciones como enviar las solicitudes, manejar las solicitudes,como las que ayudan a que estas funciones operen perfectamente, como inicializar la cola, confirmar si la cola esta vacia, poner en la cola la solicitud de amistad,quitar de la cola, mostrar la  lista de solicitudes de amistad.Aparte, tambien se encuentran las funciones que estan involucradas en las publicaciones, como la de crear una publicacion, la de imprimir las publicaciones y las que hacen eso possible. Finalmente encontramos las funciones que se ocupan de el diccionario y el contador de palabras mas usadas, entre ellas, la de la frecuencia de uso,la de ordenacion de la frecuencia, y las que lo hacen possible, como cambiar frecuencias en el diccionario y imprimir las frecuencias.

``printer.c/h``

En estos archivos se encuentran las funciones que hacen de  este gris y calmado proyecto, un poco de animo al enseñar algo de color. Eso se debe a que aquí encontramos las funciones suplementarias que hemos implementado para imprimir algunas partes del codigo, en cuanto a respuestas.

``menu.c/h``

En el archivo  se puede apreciar las definiciones que hemos usado para  aligerar la vista a  la hora de programar, para un uso menos concurrido de números y texto, haciendo el código más  entendible.

``file_reader.c/h``

En este archivo se encuentra la función readusersfromfile, que es la encargada que cargar los usuarios con sus especificaciones como usuarios dentro de la red.

``userList.txt``

Este archivo de texto, es el usado para almacenar los usuarios que se pueden cargar para no escribirlos manualmente, ahorrándote tiempo para empezar con las simulaciones.

**Gestión de errores**

Durante el proceso de hacer el trabajo, nos encontramos con algunos problemas, aqui explicamos como lo hicimos para afrontarlos.

Errores de búsqueda: Para que no cause problemas a la hora de encontrar usuarios designados en caso de equivocar-se al escribir usamos el metode de que en caso de no encontrar salir a la pantalla anterior. Esto tambien ocurre a la hora de intentar hacer amistades.

Errores al poner opciones: para que no haya problemas dentro del menu y submenus, hemos implementado una pequeña medida para que repitan hasta poner un número de opción possible.

## 4. Referencias

Durante el processo de crear el proyecto, hemos tirado de apuntes de [Estructura de datos II](https://www.upf.edu/) y memoria mayoritariamente, eso no quiere decir que no hemos recibido ayudas de sitios externos, por ejemplo, alguno hemos mirado videos sobre c para poder avanzar en nuestra comprension en el tema sobre el que trabajamos. Cabe decir que en un momento de  la produccion del proyecto, hemos echo uso de [ChatGPT](https://chat.openai.com/), no como un recreador de codigo de copypaste, sinó como a un mentor, que en el caso de devolver la solictud de vuelta a el usuario remitente, no teniamos muy claro como avanzar por ese sendero, y con una simple pregunta entendimos como tirar adelante con nuestro resultado si  tener nada que ver con el codigo proporcionado, debido a que no insertamos en ningun momento parte de nuestro codigo dentro de la IA ni tampoco extrajimos.


