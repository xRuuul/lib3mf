cd build
lcov --capture --initial --directory . --output-file Test_CPP_Bindings_base.info --ignore-errors gcov,inconsistent
./Test_CPP_Bindings

lcov --directory . --capture --output-file Test_CPP_Bindings_run.info --ignore-errors gcov,inconsistent
lcov --add-tracefile Test_CPP_Bindings_base.info --add-tracefile Test_CPP_Bindings_run.info --output-file Test_CPP_Bindings.info --ignore-errors gcov,inconsistent

TARGETDIR=`dirname \`pwd\``

lcov --remove Test_CPP_Bindings.info --ignore-errors inconsistent -o Test_CPP_Bindings_filtered.info "$TARGETDIR/Tests/*" "$TARGETDIR/Source/Libraries/*" "$TARGETDIR/Include/Libraries/*"  "$TARGETDIR/Libraries/*" "$TARGETDIR/build/*" "$TARGETDIR/submodules/*" "/Applications/*" \
  "$TARGETDIR/Autogenerated/Bindings/C/*" \
  "$TARGETDIR/Autogenerated/Bindings/CDynamic/*" \
  "$TARGETDIR/Autogenerated/Bindings/CSharp/*" \
  "$TARGETDIR/Autogenerated/Bindings/CppDynamic/*" \
  "$TARGETDIR/Autogenerated/Bindings/Go/*" \
  "$TARGETDIR/Autogenerated/Bindings/NodeJS/*" \
  "$TARGETDIR/Autogenerated/Bindings/Python/*" 


genhtml --output-directory ./codecoverage --title "lib3mf Test Coverage" --function-coverage --legend Test_CPP_Bindings_filtered.info  --ignore-errors inconsistent 

zip -r codecoverage.zip ./codecoverage/
