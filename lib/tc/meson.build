# libtc_headers = ('''
#     convert.h

#     convert_util.h

#     tc_server.h
# '''.split())

# foreach h : libtc_headers
#     if cc.has_header(h)
#         define = 'HAVE_' + h.underscorify().to_upper()
#     endif
# endforeach

libtc_sources = files('''
    convert.h

    convert_util.h

    convert_util.c

    tc_server.h

    tc_server.c
'''.split())

libtc_inc = include_directories('.')

libtc= library('ogstc',
    sources : libtc_sources,
    version : libogslib_version,
    c_args : '-DOGS_TC_COMPILATION',
    include_directories : [libtc_inc, libinc],
    dependencies : [libcore_dep, libapp_dep],
    install : true)

libtc_dep = declare_dependency(
    link_with : libtc,
    include_directories : [libtc_inc, libinc],
    dependencies : [libcore_dep, libapp_dep])
