# pd_hello_world
how to build a pd extern on linux

## building
- clone/download this repo, pb-lib-builder https://github.com/pure-data/pd-lib-builder (top level), and pure-data source https://github.com/pure-data/pure-data (need to specify the /src in the next step)
- add the paths to pd-lib-builder and pure-data source code to environment variables pd_src and pd_lib_builder (can use .bashrc by adding lines ```export [VARIABLE_NAME]=[variable_value]```)
- run make from the command line, if the previous step worked, you should see a file with the .pd_linux extension
- open up pure-data and then open the patch helloworld.pd, the bang should be connected to a solid line box
- click the bang in the patch and see the print on the console
