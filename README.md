# pd_hello_world
how to build a pd extern on linux

## building
- clone/download this repo, pb-lib-builder https://github.com/pure-data/pd-lib-builder (top level), and pure-data source https://github.com/pure-data/pure-data (need to specify the /src in the next step)
- add the paths to pd-lib-builder and pure-data source code to environment variables pd_src and pd_lib_builder (can use .bashrc by adding lines ```export [VARIABLE_NAME]=[variable_value]```). Run source on the .bashrc
- open a new shell session so the environment variables are set 
- run make from the command line. If it works, you should see a file with the .pd_linux extension
- open up pure-data and then open the patch helloworld.pd, the bang should be connected to a solid line box
- click the bang in the patch and see the print on the console


## making a new patch
Let's make a new object called rhino...
change class_new(gensym("rhino"))

the setup function needs to have that object name:

void helloworld_setup(void) => void rhino_setup(void)


rename the file:
helloworld.c => rhino.c


add rhino.c to Makefile 

Make

Try to add a rhino object to a new pd patch
