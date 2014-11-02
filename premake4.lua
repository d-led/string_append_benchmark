_G.package.path=_G.package.path..[[;./?.lua;./?/?.lua]]

assert( require 'premake.quickstart' )

make_solution 'string_append_benchmark'

includedirs {
	'./hayai/src'
}

platforms { 'x32', 'x64' }

make_console_app('string_append_benchmark', { '*.cpp' })

make_cpp11()

