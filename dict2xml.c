/**
 * dict2xml.c
 *
 * Converts Dictionary text files into MarkLogic dictionary/spell XML files
 *
 * Example, dictionary.txt containins:
 *
 * Abra
 * Cadabra
 *
 * Produces dictionary.xml, containing:
 *
 * <dictionary xmlns="http://marklogic.com/xdmp/spell">
 *  <word>Abra</word>
 *  <word>Cadabra</word>
 * </dictionary>
 *
 * @author Charles Foster
**/

#include <stdio.h>
#include <string.h>
#include <libxml/encoding.h>
#include <libxml/xmlwriter.h>

int main (int argc, char *argv[])
{
  FILE *file;
  xmlTextWriterPtr writer;

  char* inputFilename = argv[1];
  char* outputFilename = argv[2];

  if(argc != 3) {
    printf("usage: dict2xml input.txt output.xml\n");
    return 0;
  }

  file = fopen ( inputFilename, "r" );

  if(file == NULL) {
    printf("Can not read %s\n", inputFilename);
    perror ( inputFilename );
    return 1;
  }

  writer = xmlNewTextWriterFilename(outputFilename, 0);

  if(writer == NULL) {
    printf("Can not write to %s\n", outputFilename);
    return 1;
  }

  xmlTextWriterSetIndent(writer, 1);

  xmlTextWriterStartDocument(writer, NULL, "UTF-8", NULL);

  // <dictionary xmlns="http://marklogic.com/xdmp/spell">
  xmlTextWriterStartElementNS(
    writer,
    NULL,
    "dictionary",
    "http://marklogic.com/xdmp/spell"
  );

  char line [ 128 ];

  while ( fscanf (file, "%s", line) != EOF )
    xmlTextWriterWriteElement(writer, "word", line); // <word>hello</word>

  xmlTextWriterEndElement(writer); // </dictionary>
  xmlTextWriterEndDocument(writer); // END OF document-node(element())

  fclose(file);
  xmlFreeTextWriter(writer);

  return 0;
}

