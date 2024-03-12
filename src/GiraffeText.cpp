#include "GiraffeText.hpp"

#include "Util/Color.hpp"
#include "Util/Time.hpp"


void GiraffeText::Start() {
    m_Drawable = std::make_shared<Util::Text>(RESOURCE_DIR"/fonts/Inter.ttf", 75, "Pause",
                                          Util::Color::FromRGB(255, 255, 255));
    //Util::Color::FromRGB(51, 20, 0))
    m_Drawable->SetWorld(Core::Drawable::World::UI);
    m_Visible = false;
}

void GiraffeText::Update() {

}
void GiraffeText::ClickDown() {

}
void GiraffeText::ClickUp() {

}
