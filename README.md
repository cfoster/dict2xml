dict2xml
========

Simple command line utility to convert a dictionary text file into a MarkLogic dictionary / spell XML file.

Example
-------

e.g. a plain text dictionary file

```   
Abra
Cadabra
Django
Tango
Zulu
```

would produce:

```xml
<dictionary xmlns="http://marklogic.com/xdmp/spell">
  <word>Abra</word>
  <word>Cadabra</word>
  <word>Django</word>
  <word>Tango</word>
  <word>Zulu</word>
</dictionary>
```

Usage
-----

```
dict2xml input-dictionary.txt output-dictionary.xml
```

Building
--------

* Depends on libxml2
* Tested with MacOS gcc-4.2

To compile on MacOS, use the following:

```
gcc -I/usr/include/libxml2 -lxml2 -o dict2xml dict2xml.c
```

