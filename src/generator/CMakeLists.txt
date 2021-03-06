set(libmodel_SOURCES 
			generator.cpp generator.hpp
			litesql-gen-xml.cpp litesql-gen-xml.hpp 
			litesql-gen-cpp.cpp litesql-gen-cpp.hpp
			logger.cpp logger.hpp
			xmlobjects.cpp 
			md5.cpp 
			xmlobjects.hpp 
			md5.hpp 
			xmlobjects.hpp 
			litesql-gen-graphviz.cpp litesql-gen-graphviz.hpp 
			litesql-gen-ruby-activerecord.cpp litesql-gen-ruby-activerecord.hpp 
	)

set(litesql-gen_SOURCES 
			litesql-gen-main.cpp 
	)

set(ddl2litesql_SOURCES 
			ddl2litesql.cpp 
	)

# for new parser
if (LITESQL_WITH_SAX_PARSER)
   list(APPEND libmodel_SOURCES xmlparser.cpp
                                xmlparser.hpp
                                objectmodel.cpp
                                objectmodel.hpp 
)
else (LITESQL_WITH_SAX_PARSER)
   list(APPEND libmodel_SOURCES 
          litesql-gen-actions.cpp 
          litesql-gen.cpp 
          litesql-gen.hpp)
endif(LITESQL_WITH_SAX_PARSER)

add_library(model ${libmodel_SOURCES}) 
add_executable(litesql-gen ${litesql-gen_SOURCES})
add_executable(ddl2litesql ${ddl2litesql_SOURCES})

target_link_libraries (litesql-gen litesql litesql-util model ${EXPAT_LIBRARIES})
target_link_libraries (ddl2litesql litesql-util model ${EXPAT_LIBRARIES})

if (LITESQL_WITH_UI)
  add_subdirectory(ui)
# old stuff which does not work
#  if (MSVC)
#    add_subdirectory(win32-ui)
#  endif(MSVC)
endif(LITESQL_WITH_UI)



install(TARGETS litesql-gen RUNTIME DESTINATION bin COMPONENT generator)
INCLUDE_DIRECTORIES(../library ${EXPAT_INCLUDE_DIRS})
