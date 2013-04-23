/**
* Begin svn Header
* $Rev::		$:	Revision of last commit
* $Author::		$:	Author of last commit
* $Date::		$:	Date of last commit
* $HeadURL::	$
* $Id::			$
* End svn Header
* ****************************************************************************
* This file is part of libNUML.  Please visit http://code.google.com/p/numl/for more
* information about NUML, and the latest version of libNUML. 
* Copyright (c) 2013 The University of Manchester.
* 
* This library is free software; you can redistribute it and/or modify it
* under the terms of the GNU Lesser General Public License as published
* by the Free Software Foundation.  A copy of the license agreement is 
* provided in the file named "LICENSE.txt" included with this software 
* distribution and also available online as http://www.gnu.org/licenses/lgpl.html 
* 
* The original code was initially developed by:
* 
*      SBML Team
*      Control and Dynamical Systems, MC 107-81
*      California Institute of Technology
*      Pasadena, CA, 91125, USA
* 
*      http://www.sbml.org
*      mailto:sbml-team@caltech.edu
* 
* Adapted for NUML by:
* 
*   NUML Team
*   Computational Systems Biology Group
*   School of Computer Science
*   The University of Manchester
*   Manchester, UK
* 
*   Contributor(s):
*   Joseph O. Dada, The University of Manchester - initial LIBNUML API and implementation
* ****************************************************************************
**/

#include <numl/xml/LibXMLTranscode.h>
#include <numl/xml/LibXMLAttributes.h>

/** @cond doxygen-ignored */

using namespace std;

/** @endcond doxygen-ignored */

LIBNUML_CPP_NAMESPACE_BEGIN

/** @cond doxygen-libnuml-internal */

/**
 * Creates a new XMLAttributes set from the given "raw" LibXML attributes.
 */
LibXMLAttributes::LibXMLAttributes (  const xmlChar** attributes
				    , const xmlChar*  elementName
                                    , const unsigned  int& size )
{
  mNames .reserve(size);
  mValues.reserve(size);

  for (unsigned int n = 0; n < size; ++n)
  {
    const string name    = LibXMLTranscode( attributes[5 * n]     );
    const string prefix  = LibXMLTranscode( attributes[5 * n + 1] );
    const string uri     = LibXMLTranscode( attributes[5 * n + 2], true );

    const xmlChar* start = attributes[5 * n + 3];
    const xmlChar* end   = attributes[5 * n + 4];
    int length           = (end - start) / sizeof(xmlChar);

    const string value   =  LibXMLTranscode((length > 0) ? start : 0, true, length);

    mNames .push_back( XMLTriple(name, uri, prefix) );
    mValues.push_back( value );
  }

  mElementName = LibXMLTranscode(elementName);
}


/**
 * Destroys this Attribute set.
 */
LibXMLAttributes::~LibXMLAttributes ()
{
}

/** @endcond doxygen-libnuml-internal */

LIBNUML_CPP_NAMESPACE_END
