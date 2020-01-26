#include "AudioEngine.h"
#include "../../../../oboe/src/common/OboeDebug.h"

void AudioEngine::start() {

    AudioStreamBuilder builder;
    build.setDirection(Direction::Input);
    builder.setPerformanceMode(PerformanceMode::LowLatency);

    AudioStream *stream;
    Result r = builder.openStream(&stream);
    if (r != Result::OK){
        LOGE("Error opening stream: %s", convertToText(r));
    }

    r = stream->requestStart();
    if (r != Result::OK){
        LOGE("Error starting stream: %s", convertToText(r));
    }

}