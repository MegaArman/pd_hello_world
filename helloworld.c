/* creates an object that prints "Hello world!" whenever it 
 * gets banged.
 */

//Get the Pure Data headers from: https://github.com/pure-data/pure-data/blob/master/src/m_pd.h
#include "m_pd.h"

// PureData "class" declaration with t_class
static t_class *helloworld_class;

//class interface
typedef struct _helloworld { 
  t_object  x_obj; //mandatory object internal
} t_helloworld; //this is the type name you will use

/**
 * this method is called whenever a "bang" is sent to the object
 * registered to Pd in the helloworld_setup() routine
 */
void helloworld_bang(t_helloworld *x)
{
  /*
   * post() is Pd's version of printf()
   */
  post("Hello world !!");
}

/**
 * this is the "constructor" of the class 
 * registered to Pd in the helloworld_setup() routine
 */
void *helloworld_new(void)
{
  /*
   * call the "constructor" of the parent-class, pd_new,
   * which will reserve  memory for a "t_helloworld" object
   */
  t_helloworld *x = (t_helloworld *)pd_new(helloworld_class);

  //must return pointer to the class
  return (void *)x;
}

/**
 * define the function-space of the class
 * within a single-object external the name of this function is special
 */
void helloworld_setup(void) {
  /* create a new class */
  helloworld_class = class_new(gensym("helloworld"),        /* the PD object's name you'll type "helloworld" */
			       (t_newmethod)helloworld_new, /* the object's constructor is "helloworld_new()" */
			       0,                           /* no special destructor */
			       sizeof(t_helloworld),        /* the size of the data-space */
			       CLASS_DEFAULT,               /* a normal pd object */
			       0);                          /* no creation arguments */

  /* attach functions to messages */
  /* here we bind the "helloworld_bang()" function to the class "helloworld_class()" -
   * it will be called whenever a bang is received
   */
  class_addbang(helloworld_class, helloworld_bang); 
}
