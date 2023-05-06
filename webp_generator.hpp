
#ifndef WEBP_GENERATOR_HPP_INCLUDED
#define WEBP_GENERATOR_HPP_INCLUDED

#include <chrono>
#include <vector>
#include <QByteArray>
#include <QImage>

#include <animatedwebp_export.h>


class ANIMATEDWEBP_EXPORT WebPGenerator
{
    public:
        /**
         * @brief Append frame.
         */
        WebPGenerator& append(const QImage &);

        /**
         * @brief Set delay between changing frames.
         *
         * Defines how long each frame will be shown during animation.
         */
        WebPGenerator& setDelay(const std::chrono::milliseconds &);

        /**
         * @brief Set delay before starting animation again.
         *
         * Set 0 for no delay
         */
        WebPGenerator& setLoopDelay(const std::chrono::milliseconds &);

        /**
         * @brief Use lossless compression.
         */
        WebPGenerator& setLossless();

        /**
         * @brief Generate file content.
         */
        QByteArray save();

    private:
        std::vector<QImage> m_frames;
        std::chrono::milliseconds m_delayForFrames = std::chrono::milliseconds(100);
        std::chrono::milliseconds m_delayForLoop = std::chrono::milliseconds(0);
        bool m_lossless = false;
};

#endif
