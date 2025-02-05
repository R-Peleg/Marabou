#include "InputQueryBuilder.h"
#include "OnnxParser.h"

#include <cstdint>


void callParserForFuzzing( const uint8_t *Data, size_t Size )
{
    InputQueryBuilder queryBuilder;
    OnnxParser parser = OnnxParser( queryBuilder, Data, Size, {}, {} );
    parser.processGraph();
}


extern "C" {
int LLVMFuzzerTestOneInput( const uint8_t *Data, size_t Size )
{
    callParserForFuzzing( Data, Size );
    return 0;
}
}
