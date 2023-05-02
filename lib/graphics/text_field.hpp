#ifndef TEXT_FIELD_HPP
#define TEXT_FIELD_HPP


#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>

class Text_Field : public sf::Transformable, public sf::Drawable {
    public:
        Text_Field(int strt_x, int strt_y, int width, int height, const std::string &message) :
            // size_(30),
            message_ (message),
            rect_ (sf::Vector2f (width, height)), // 15 pixels per char, 20 pixels height, you can tweak
            hasfocus_(false)
        {
            rect_.setOutlineThickness(2);
            rect_.setFillColor(sf::Color::White);
            rect_.setOutlineColor(sf::Color(127, 127, 127));
            // m_rect.setPosition(this->getPosition());
            rect_.move (sf::Vector2f (strt_x, strt_y));

            font_.loadFromFile("./data/fonts/ARIAL.TTF");
            text_.setString (message_);
            text_.setFont(font_);
            text_.setFillColor(sf::Color::Black);
            text_.setStyle(sf::Text::Bold);
            text_.move (sf::Vector2f (strt_x, strt_y));
            text_.setCharacterSize (20);
        }

        const std::string getMessage() const{
            return message_;
        }
        
        void set_message (const std::string &message) {
            message_ = message;
            text_.setString (message_);
        }

        void setPosition (float x, float y) {
            sf::Transformable::setPosition(x, y);
            rect_.setPosition(x, y);
        }
        
        sf::FloatRect getGlobalBounds () {
            return rect_.getGlobalBounds ();
        }

        bool contains(sf::Vector2f point) const {
            return rect_.getGlobalBounds().contains(point);
        }
        
        void setFocus (bool focus) {
            hasfocus_ = focus;
            if (focus){
                rect_.setOutlineColor(sf::Color::Blue);
            }
            else{
                rect_.setOutlineColor(sf::Color(127, 127, 127)); // Gray color
            }
        }

    private:
        void draw(sf::RenderTarget& target, sf::RenderStates states) const override {
            target.draw (rect_, states);

            target.draw (text_, states);
        }

        // int size_;
        sf::Font font_;
        std::string message_;
        sf::RectangleShape rect_;
        bool hasfocus_;
        sf::Text text_;
};

#endif