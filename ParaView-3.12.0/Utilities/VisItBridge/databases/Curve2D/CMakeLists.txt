
SET(SOURCES
avtCurve2DFileFormat.C
)
ADD_VISIT_READER(VisItCurve2DReader "1.0"
  VISIT_READER_TYPE "STSD"
  VISIT_READER_NAME "avtCurve2DFileFormat"    
  SERVER_SOURCES ${SOURCES}
  )
