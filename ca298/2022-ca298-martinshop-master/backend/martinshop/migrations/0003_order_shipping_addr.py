# Generated by Django 4.0.1 on 2022-02-06 22:06

from django.db import migrations, models


class Migration(migrations.Migration):

    dependencies = [
        ('martinshop', '0002_basket_product_order_basketitem'),
    ]

    operations = [
        migrations.AddField(
            model_name='order',
            name='shipping_addr',
            field=models.TextField(default=''),
        ),
    ]
