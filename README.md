dict2xml
========

Simple command line utility to convert a dictionary text file into a MarkLogic dictionary / spell XML file.

example
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

usage
-----

```
dict2xml input-dictionary.txt output-dictionary.xml
```


