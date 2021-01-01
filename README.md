# translate-language
translate English-based programming languages to be more inviting for those in non-English countries

This is an idea I had after reading an article about the [prevelance of english within programming](https://www.google.ca/amp/s/www.wired.com/story/coding-is-for-everyoneas-long-as-you-speak-english/amp). 
After realising how english centric the world of software is and how uninviting it can be for those with non-english backgrounds, I began looking around to see if there have been other attempts at resolving this problem. Although some language specific attempts exist (and some even [quite successful](https://github.com/metaphorm/international-scheme)), I was unable to find any that acted as a general tool and so I thought I would do my part by making a tool that could hopefully solve this or atleast provide a starting point for a solution to this problem. 

This is a relatively simple translation tool at its current stage. It takes in a translation file that acts as a mapping or dictionary from one language to another. It then applies this dictionary to a file to translate it from one language to another. 


All the source code is currently under main. An example translation file for the c programming language that goes from english to french is also available.
To test this, you can run this against any c program. 

To do so, first simply compile it with your compiler of choice. e.g. `g++ main.cc -o translate`
Then after compilation, you can run something like this: `./translate c-en-fr test.c`
Where "test.c" is a c program.

For example, a c simple c program that looks like this:
```
int main() {
  return 0;
}
```
would be translate into something like:
```
ent principale() {
  retourne 0;
}
```

This system can be easily extendable to more languages by simply adding more of these translation files.
