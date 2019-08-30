using System;
using System.IO;
using System.Linq;
using System.Text;
using System.Xml;
using System.Xml.Linq;
using System.Xml.Schema;

namespace CreatingXMLDocument
{
    class Program
    {
        static void Main(string[] args)
        {
            var bookObj = new BookStore();

            var bookList = bookObj.GetBookStores();

            XDocumentType docType = new XDocumentType("bookstoredoc", null,
                null,
                @"<!ELEMENT bookstore (book+)>
                <!ELEMENT book (title|year|price|author+) >
                <!ATTLIST book
                    category CDATA #REQUIRED>
                <!ELEMENT title (#PCDATA)>
                <!ATTLIST title
                  lang CDATA #REQUIRED>
                <!ELEMENT year (#PCDATA)>
                <!ELEMENT price (#PCDATA)>
                <!ELEMENT author (name+)>
                <!ELEMENT name (#PCDATA)>");

            var xmlDocument = new XDocument(new XElement("bookstore",
                bookList.Select(x =>
                    new XElement("book", new XAttribute("category", x.Category),
                    new XElement("title", new XAttribute("lang", x.Lang), x.Title),
                    new XElement("year", x.Year),
                    new XElement("price", x.Price),
                    new XElement("author", x.Author.Select(y => new XElement("name", y.Name)))
               ))));



            xmlDocument.Save(@"D:\Test.xml");
            XmlReader reader = XmlReader.Create(@"D:\Test.xml");
            XmlSchemaSet schemaSet = new XmlSchemaSet();
            XmlSchemaInference schema = new XmlSchemaInference();
            schemaSet = schema.InferSchema(reader);



            foreach (XmlSchema s in schemaSet.Schemas())
            {
                using (var stringWriter = new StringWriter())
                {
                    using (var writer = XmlWriter.Create(stringWriter))
                    {
                        s.Write(writer);
                    }

                    string text = stringWriter.ToString();
                }
            }

            Console.WriteLine("Hello World!");


        }
    }
}

