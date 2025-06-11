#include "food_order.h"

int process_food_order(struct OrderRequest *request)
{
	return check_restaurant_status(request) ? send_confirmation_notification(create_standard_confirmation()), 1 : send_confirmation_notification(create_preorder_confirmation()), 0;
}