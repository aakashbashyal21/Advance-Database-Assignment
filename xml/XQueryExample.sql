DECLARE @x xml
SET @x = '
<bookstore>
  <book category="COOKING">
    <title lang="en">Everyday Italian</title>
    <year>2005</year>
    <price>30</price>
    <author>
      <name>Giada De Laurentiis</name>
    </author>
  </book>
  <book category="COOKING">
    <title lang="en">The Joy of Cooking</title>
    <year>1931</year>
    <price>20.78</price>
    <author>
      <name>Irma S. Rombauer</name>
    </author>
  </book>
  <book category="COOKING">
    <title lang="en">Everyday Italian</title>
    <year>2005</year>
    <price>30</price>
    <author>
      <name>Giada De Laurentiis</name>
    </author>
  </book>
  <book category="CHILDREN">
    <title lang="en">Harry Potter</title>
    <year>2005</year>
    <price>29.99</price>
    <author>
      <name>J K. Rowling</name>
    </author>
  </book>
  <book category="WEB">
    <title lang="en">XQuery Kick Start</title>
    <year>2003</year>
    <price>49.99</price>
    <author>
      <name>James McGovern</name>
      <name>Per Bothner</name>
      <name>Kurt Cagle</name>
      <name>James Linn</name>
      <name>Vaidyanathan Nagarajan</name>
    </author>
  </book>
  <book category="WEB">
    <title lang="en">Learning XML</title>
    <year>2003</year>
    <price>39.95</price>
    <author>
      <name>Erik T. Ray</name>
    </author>
  </book>
  <book category="WEB">
    <title lang="en">Database System Concepts</title>
    <year>1986</year>
    <price>95.55</price>
    <author>
      <name>Avi Silberschatz</name>
      <name>Henry F. Korth</name>
      <name>S. Sudarshan</name>
    </author>
  </book>
</bookstore>'

/*Query that returns the list of all the author*/
SELECT @x.query('   
for $book in /bookstore/book/author,
      $author in $book/name
	  return 
		$author
')

/*Query that returns the list of the book with the category = WEB*/
SELECT @x.query('   
for $book in /bookstore/book 
		where $book/@category = "WEB"
	  return
	  <book year="{$book/year/text()}"> 
		{$book/title/text()} 
	  </book> 
')

/*Query that returns the title of the book with the category = COOKING*/
--SELECT @x.query('   
--for $book in /bookstore/book
--		where $book/@category = "COOKING"
--	  return $book/title
--')
/*Query that returns by sorting the record by year*/
--select @x.query('for $book in /bookstore/book
--order by $book/year[1]  
--return
--	<book year="{$book/year/text()}"> 
--		{$book/title/text()} 
--	</book> 
--')  
/*Query that returns by sorting the record by year*/
--select @x.query('  
--  for $book in /bookstore/book
--  order by $book/year[1]  
--  return   $book  
--')  

/*Query that returns the total count of the data*/
--select @x.query('  
--let $b := /bookstore/book
--let $count := count($b)
--return $count
--')

/*Query that returns the books with more than one author*/
select @x.query('  
for $book in /bookstore/book,
    $author in $book/author
	where count($author/name) > 3
return $book
')


