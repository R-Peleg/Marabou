#include "InputQueryBuilder.h"
#include "OnnxParser.h"

#include <cstdint>


void callParserForFuzzing( const uint8_t *Data, size_t Size )
{
    if ( Size == 0 )
    {
        return;
    }
    InputQueryBuilder queryBuilder;
    try
    {
        OnnxParser parser = OnnxParser( queryBuilder, Data, Size, {}, {} );
        parser.processGraph();
    }
    catch ( ... )
    {
    }
}


extern "C" {
int LLVMFuzzerTestOneInput( const uint8_t *Data, size_t Size )
{
    callParserForFuzzing( Data, Size );
    return 0;
}
}
