simulator_api

# SETUP
Inside unity_method_definitions.cpp(TODO: CHANGE THIS LOCATION), setup ur
project path vars at the top of the file.

NOTE: sometimes the unity dll reloader plugin doesn't unload the unity dll, just tab back in and out to fix this
Sometimes if you remove a method definition and there is an error inside unity, you will need to restart unity to be able to write 
to the plugin dll

NOTE: "c1xx : fatal error C1083: Cannot open source file:" --> Fix this by reloading cmake project.
In CLion its Tools --> Cmake --> Reset CMake Cache & Reload Project