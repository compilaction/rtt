.. _rtt-container-literal-string:

literal_string
==============

.. doxygenstruct:: rtt::literal_string
   :project: rtt

.. _rtt-container-literal-string-types:

Types
^^^^^

.. list-table::
   :widths: 5,12
   :header-rows: 1

   * - Name
     - Default Value

       .. _rtt-container-literal-string-value_type:
   * - ``value_type``
     - Underlying character type

       .. _rtt-container-literal-string-pointer:
   * - ``pointer``
     - Associated pointer type

       .. _rtt-container-literal-string-const_pointer:
   * - ``const_pointer``
     - Associated pointer to constant type

       .. _rtt-container-literal-string-iterator:
   * - ``iterator``
     - Associated iterator type

       .. _rtt-container-literal-string-const_iterator:
   * - ``const_iterator``
     - Associated constant iterator type

       .. _rtt-container-literal-string-reference:
   * - ``reference``
     - Associated reference type

       .. _rtt-container-literal-string-const_reference:
   * - ``const_reference``
     - Associated reference to constant type

.. _rtt-container-literal-string-ctors:

Constructors
^^^^^^^^^^^^

.. _rtt-container-literal-string-ptr-ctor:

.. doxygenfunction:: rtt::literal_string::literal_string(const_pointer)
   :project: rtt

**Example:**

.. literalinclude:: ../../../test/doc/container/literal_string.cpp
   :language: cpp
   :lines: 12-14

.. _rtt-container-literal-string-copy-ctor:

.. doxygenfunction:: rtt::literal_string::literal_string(literal_string const&)
   :project: rtt

**Example:**

.. literalinclude:: ../../../test/doc/container/literal_string.cpp
   :language: cpp
   :lines: 17-20

.. _rtt-container-literal-string-members:

Member functions
^^^^^^^^^^^^^^^^

.. _rtt-container-literal-string-equality:

.. doxygenfunction:: rtt::literal_string::operator==(literal_string const&)
   :project: rtt

.. _rtt-container-literal-string-inequality:

.. doxygenfunction:: rtt::literal_string::operator!=(literal_string const&)
   :project: rtt

.. _rtt-container-literal-string-begin:

.. doxygenfunction:: rtt::literal_string::begin
   :project: rtt

.. _rtt-container-literal-string-end:

.. doxygenfunction:: rtt::literal_string::end
   :project: rtt

.. _rtt-container-literal-string-size:

.. doxygenfunction:: rtt::literal_string::size
   :project: rtt

.. _rtt-container-literal-string-count:

.. doxygenfunction:: rtt::literal_string::count
   :project: rtt

.. _rtt-container-literal-string-subscript:

.. doxygenfunction:: rtt::literal_string::operator[]
   :project: rtt
